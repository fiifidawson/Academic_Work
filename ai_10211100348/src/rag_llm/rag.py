# rag_streamlit.py
import streamlit as st
import os
import pandas as pd
import chromadb
from chromadb import Documents, EmbeddingFunction, Embeddings
import google.generativeai as genai
from PyPDF2 import PdfReader
from langchain.text_splitter import RecursiveCharacterTextSplitter
from langchain_core.documents import Document
import time
from tqdm import tqdm
import config
from config import GEMINI_API_KEY

# --- SQLite Fix for Chroma ---
__import__('pysqlite3')
import sys
sys.modules['sqlite3'] = sys.modules.pop('pysqlite3')

# Initialize Gemini 
os.environ["GEMINI_API_KEY"] = config.GEMINI_API_KEY
genai.configure(api_key=os.environ["GEMINI_API_KEY"])

class GeminiEmbeddingFunction(EmbeddingFunction):
    def __call__(self, input: Documents) -> Embeddings:
        return genai.embed_content(
            model='models/embedding-001',
            content=input,
            task_type="retrieval_document",
            title="Academic City Student Handbook 2024"
        )["embedding"]

def process_pdf(file_path):
    pdf_reader = PdfReader(file_path)
    text = "".join(page.extract_text() for page in pdf_reader.pages[7:])
    return text

def clean_text(text):
    cleaned = "\n".join(line for line in text.split('\n') if len(line) > 10 and text.split('\n').index(line) > 70)
    return cleaned.replace('~', '').replace('©', '').replace('_', '').replace(';:;', '')

def create_chunks(text):
    splitter = RecursiveCharacterTextSplitter(
        chunk_size=1000,
        chunk_overlap=100,
        length_function=len,
        add_start_index=True
    )
    return splitter.split_text(text)

def initialize_db():
    client = chromadb.PersistentClient(path="data/rag_llm/chroma_db")
    return client.get_or_create_collection(
        name="sme_db", 
        embedding_function=GeminiEmbeddingFunction()
    )

def extract_confidence(response_text):
    try:
        if "Confidence:" in response_text:
            return response_text.split("Confidence: ")[1].split("%")[0] + "%"
        return "N/A"
    except:
        return "N/A"

def main():    
    if 'history' not in st.session_state:
        st.session_state.history = []
    if 'db' not in st.session_state:
        st.session_state.db = initialize_db()
    
    with st.sidebar:
        st.header("Session History")
        for idx, item in enumerate(st.session_state.history):
            st.markdown(f"**Q{idx+1}:** {item['question']}")
            st.markdown(f"**Confidence:** {item['confidence']}")
            st.markdown(f"**A{idx+1}:** {item['answer']}")
            st.divider()
        
        if st.button("Clear History"):
            st.session_state.history = []
            
        if st.session_state.history:
            csv = pd.DataFrame(st.session_state.history).to_csv(index=False)
            st.download_button(
                label="Export History",
                data=csv,
                file_name="qa_history.csv",
                mime="text/csv"
            )

    st.header("💬 Academic City Handbook Q&A System")
    
    # Database initialization with metadata
    if st.session_state.db.count() == 0:
        with st.spinner("First-time setup: Processing handbook..."):
            text = process_pdf("data/rag_llm/ACITY_HANDBOOK.pdf")
            cleaned = clean_text(text)
            chunks = create_chunks(cleaned)
            
            # Create documents with metadata
            documents = [
                Document(
                    page_content=chunk,
                    metadata={"source": "handbook", "chunk_id": i}
                ) for i, chunk in enumerate(chunks)
            ]
            
            # Add to Chroma with metadata
            st.session_state.db.add(
                documents=[doc.page_content for doc in documents],
                metadatas=[doc.metadata for doc in documents],
                ids=[str(doc.metadata["chunk_id"]) for doc in documents]
            )

    query = st.text_input("Enter your question about the handbook:")
    st.caption("Controls how many text segments from the handbook are analyzed to generate answers. Higher values may improve accuracy but increase processing time.")
    n_results = st.slider("Number of reference passages", 1, 10, 5)

    if st.button("Submit"):
        with st.spinner("Analyzing..."):
            try:
                results = st.session_state.db.query(
                    query_texts=[query],
                    n_results=n_results,
                    include=["documents", "metadatas", "distances"]
                )
                
                # Extract results with metadata
                passages = results['documents'][0]
                metadatas = results['metadatas'][0]
                distances = results['distances'][0]
                
                context = "\n".join(passages)
                prompt = f"""question: {query}
                Additional context: {context}
                If irrelevant, respond 'Out of context. Kindly ask a question related to the student handbook.'
                Include a confidence estimate between [0-100%]
                Your answer:"""
                
                model = genai.GenerativeModel('gemini-2.0-flash')
                response = model.generate_content(prompt)
                confidence = extract_confidence(response.text)
                
                st.session_state.history.append({
                    "question": query,
                    "answer": response.text,
                    "confidence": confidence,
                    "retrieval_scores": str(distances),
                    "context": context,
                    "metadata": str(metadatas)
                })

                col1, col2 = st.columns([3,1])
                with col1:
                    st.subheader("Response")
                    st.markdown(response.text)
                with col2:
                    st.metric("Confidence Score", confidence)
                    avg_score = sum(distances)/len(distances) if distances else 0
                    st.metric("Avg Retrieval Score", f"{avg_score:.2f}")
                
                st.divider()
                with st.expander("View Retrieval Metadata"):
                    st.write("**Passage Scores:**", distances)
                    st.write("**Document Metadata:**", metadatas)
                    st.write("**Reference Context:**", context)
                
            except Exception as e:
                if 'quota' in str(e).lower() or 'rate limit' in str(e).lower():
                    st.error("API rate limit exhausted - please wait before making new requests")
                    st.warning("""
                    ⚠️ **Rate Limit Exceeded**  
                    Our system is experiencing high demand. Please:  
                    - Wait 1-2 minutes before trying again  
                    - Consider upgrading your API plan for higher limits  
                    - Contact support@acity.edu.gh for assistance  
                    """)
                else:
                    st.error(f"Error processing query: {str(e)}")

    st.markdown("---")
    st.caption("© 2025 AI Suite - Student Handbook Q&A Module v1.0")

if __name__ == "__main__":
    main()

# https://www.youtube.com/watch?v=8xVmzoP1lks
# https://github.com/karndeepsingh/ApplicationsBuildWithLLMs/blob/main/Langchain_With_Gemini_And_Build_RAG.ipynb
# https://www.figma.com/board/aYqqN6OFAUl1rztzLMb07l/Architecture-Diagram-Example---Multiplayer--Community-?node-id=0-1&p=f&t=IMx5sTOXWt2LcELD-0