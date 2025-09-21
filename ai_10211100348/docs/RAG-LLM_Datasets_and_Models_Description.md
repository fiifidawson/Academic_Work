<!-- PROJECT LOGO -->
<br />
<div align="center">
<h3 align="center">RAG-LLM Dataset and Models Description</h3>

  <p align="center">
    This document gives a detailed description of the dataset and models used in the development of the Academic City Handbook Q&A System.
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
      <a href="#datasets">Datasets</a>
      <ul>
        <li><a href="#source-document">Source Document</a></li>
      </ul>
    </li>
    <li>
      <a href="#Models">Models</a>
      <ul>      
        <li><a href="#embedding-model">Embedding Model</a></li>
        <li><a href="#generative-model">Generative Model</a></li>   
        <li><a href="#retrieval-system">Retrieval System</a></li>     
      </ul>
    </li>
    <li><a href="#key-metrics">Key Metrics</a>
    <ul>
        <li><a href="#embedding-model-eval">Embedding Model Eval</a></li>
        <li><a href="#limitations">Limitations</a></li>
      </ul>    
    </li> 
  </ol>
</details>

## Datasets

### Source Document:

#### ACITY_HANDBOOK.pdf
1. A 77-page student handbook containing policies, regulations, academic guidelines, and campus rules for [Academic City University College (2024 edition)](https://github.com/fiifidawson/ai_10211100348/blob/main/data/rag_llm/ACITY_HANDBOOK.pdf).

2. Content spans admissions, code of conduct, academic integrity, hostel management, COVID-19 policies, and more.


#### Processing Pipeline:
1. **Text Extraction:**
    - Uses `PyPDF2` to extract text starting from Page 7 onward (skipping cover pages and table of contents).
    - Concatenates text from all pages into a single string.

2. **Text Cleaning:**
    - Removes special characters (`~, ©, _, ;:;`).
    - Filters out short lines (<10 characters) and irrelevant header/footer content.

3. **Chunking:**
    - Splits text into chunks of 1,000 characters with 100-character overlap using `RecursiveCharacterTextSplitter`.
    - Produces ~75-100 semantic chunks for vector storage.


## Models

### Embedding Model
- **Google Gemini** `models/embedding-001`
    - Task type: `retrieval_document`

    - Generates dense vector representations (embeddings) for text chunks.

    - Used to populate a ChromaDB vector database (collection:`sme_db`).


### Generative Model
- **Google Gemini** `gemini-2.0-flash`
    - Takes user queries and retrieved context chunks to generate answers.

    - Prompt template:
        ```sh
        question: {query}
        Additional context: {context}
        If irrelevant, respond 'Out of context...'
        Include a confidence estimate [0-100%] 
        ```


### Retrieval System
- **ChromaDB**
    - Task type: `retrieval_document`

    - Config:
        - `n_results` adjustable via slider (default: 5 passages).
        - Distance metrics used for ranking retrieved passages.


## Key Metrics

### Embedding Model Eval
- **Google Gemini:** Extracted from response text (e.g., `Confidence: 85%`).

- **Average Score:** Average of embedding distances (lower = better relevance). 

### Limitations
- **Google Gemini:** Gemini API quotas may trigger errors during high usage.
- **Confidence Estimation:** Relies on model’s self-assessment, not calibrated externally.