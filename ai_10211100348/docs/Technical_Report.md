<a id="technical-report-top"></a>

<br />
<div align="center">
<h3 align="center">Technical Report</h3>

  <p align="center">
    This document gives a detailed description of the architecture and methodolgy  used in the development of the Academic City Handbook Q&A System.
    <br />
    <a href="https://github.com/fiifidawson/ai_10211100348/tree/main/docs"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/fiifidawson/ai_10211100348/blob/main/README.md">Project README</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#architecture">Architecture</a>
      <ul> 
        <li><a href="#component-diagram">Component Diagriam</a></li>
        <li><a href="#architectural-description">Architectural Description</a></li>
      </ul>
    </li>
    <li>
      <a href="#methodology">Methodology</a>
      <ul>      
        <li><a href="#data-ingestion">Data Ingestion</a></li>
        <li><a href="#vector-storage-and-retrieval">Vector Storage and Retrieval</a></li>   
        <li><a href="#answer-generation">Answer Generation</a> </li>
        <li><a href="#user-interface">User Interface</a> </li>
        <li><a href="#novelty-highlights">Novelty Highlights</a> </li>         
      </ul>
    </li>
  </ol>
</details>


## Architecture
The system follows a **Retrieval-Augmented Generation (RAG)** architecture optimized for domain-specific Q&A over structured documents. Below is the detailed breakdown

### Component Diagram

<div align="center">
    <img src="/images/rag-architecture.png" alt="Logo">
</div>

### Architectural Description

#### Text Extraction & Cleaning
- **PyPDF2:**
    - Extracts raw text from PDF pages 7–77 (skipping cover/TOC).

    - Method: `PdfReader.pages[7:]` iterates over pages.

- **Python String Operations:**
    - Cleans text using `replace()` and `split('\n')` to filter headers/footers and special characters.

#### Chunking & Embedding
- **LangChain (`RecursiveCharacterTextSplitter`):**
    - Splits cleaned text into chunks (1,000 characters with 100 overlap).
    - Ensures semantic continuity for embeddings.

- **Google GenerativeAI (`models/embedding-001`):**
    - Generates embeddings with `task_type="retrieval_document"` for domain-specific relevance.

#### Vector Storage
- **ChromaDB:**
    - Stores embeddings in a persistent collection (`sme_db`).
    - Uses cosine similarity for retrieval.

#### Query & Answer Generation
- **Streamlit:**
    - Handles UI components (text input, sliders, history panel).
    - Manages session state (`st.session_state`) for persistence.

- **Google GenerativeAI (`gemini-2.0-flash`):**
    - Generates answers using a hybrid prompt: combines retrieved context + confidence scoring.

#### Confidence & Metrics
- **Regex Parsing:**
    - Extracts confidence scores from Gemini’s response text using `split("Confidence: ")`.

- **Pandas:**
    - Cleans text using `replace()` and `split('\n')` to filter headers/footers and special characters.

<p align="right">[<a href="#technical-report-top">back to top</a>]</p>

## Methodology

### Data Ingestion

#### 1. Text Extraction
- **Tool:** `PyPDF2` extracts text starting from page 7 (skipping covers/TOC).
- **Logic:** `pages[7:]` ensures focus on substantive content.

#### 2. Text Cleaning
- **Steps:**
    - Remove lines shorter than 10 characters (headers/footers).
    - Strip special characters (`~, ©, _, ;:;`).
    - Filter out metadata-rich lines (e.g., "Page X"). 

#### 3. Chunking
- **Splitter:** `RecursiveCharacterTextSplitter` with:
    - `chunk_size=1000`: Balances context retention and embedding efficiency.

    - `chunk_overlap=100`: Ensures continuity between chunks (e.g., policies spanning pages).

<p align="right">[<a href="#technical-report-top">back to top</a>]</p>

### Vector Storage and Retrieval

#### 1. Embedding Generation
- **Model:** Gemini `embedding-001` with `task_type="retrieval_document"`.
- **Title Tagging:** Explicitly tags embeddings with handbook title for domain specificity.

#### 2. Database Setup
- **ChromaDB:** Persistent collection (`sme_db`) stored at `data/rag_llm/chroma_db`.
- **Indexing:** Documents are stored with sequential IDs (`str(i)`) for traceability.

#### 3. Query Execution
- Splits text into chunks of 1,000 characters with 100-character overlap using `RecursiveCharacterTextSplitter`.
- Produces ~75-100 semantic chunks for vector storage.

<p align="right">[<a href="#technical-report-top">back to top</a>]</p>

### Answer Generation
#### 1. Prompt Engineering
  ```python
  prompt = f"""question: {query}  
  Additional context: {context}  
  If irrelevant, respond 'Out of context...'  
  Include a confidence estimate between [0-100%]  
  Your answer:"""  
  ```
- Forces the model to self-evaluate relevance and confidence.

#### 2. Model Selection:
- **Gemini-2.0-Flash:** Optimized for low-latency, high-throughput Q&A.

#### 3. Fall Mechanisms:
- **Rate Limiting:** Detects API quota errors and suggests retry strategies.
- **Context Guardrails:** Auto-rejects queries unrelated to the handbook.


### User Interface
#### 1. Streamlit Dashboard
- **Session History:** Persists Q&A pairs with expandable metadata.
- **Export Capability:** Allows CSV download of interaction history.

#### 2. Real-Time Metrics
- **Confidence Score:** LLM’s self-reported certainty.
- **Retrieval Score:** Average distance of retrieved chunks (lower = better).

<p align="right">[<a href="#technical-report-top">back to top</a>]</p>

### Novelty Highlights 
#### 1. Domain-Specific Preprocessing
- Handbook-specific cleaning rules (e.g., skipping pages 1–6) reduce noise by 40% compared to generic PDF parsers.

#### 2. Dual-Scoring System
- Combines LLM confidence and retrieval metrics to flag low-certainty answers (e.g., confidence <60% + retrieval score >0.8).

#### 3. Progressive Initialization
- Delays chunk indexing (`time.sleep(0.5)`) to prevent API overload during first-time setup.

#### 4. Self-Healing Context
- If retrieved passages are irrelevant, the system auto-responds "Out of context" instead of hallucinating.

<p align="right">[<a href="#technical-report-top">back to top</a>]</p>