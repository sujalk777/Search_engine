# Search Engine
  
A lightweight search engine implementation. This project demonstrates the core functionalities of a search engine, including **indexing**, **query processing**, and **ranking** of documents based on relevance. Built using C++, the search engine utilizes advanced data structures like hash maps, tries, and heaps to efficiently handle large datasets.

---

## Table of Contents
1. [Features](#features)
2. [How It Works](#how-it-works)
3. [Installation](#installation)
4. [Usage](#usage)
5. [File Structure](#file-structure)
6. [Technologies Used](#technologies-used)
7. [Contributing](#contributing)
8. [License](#license)

---

## Features

- **Inverted Indexing**: Efficiently maps terms to the documents containing them.
- **Query Processing**: Supports single-word, multi-word, and Boolean queries (AND, OR).
- **Ranking**: Implements **TF-IDF** (Term Frequency-Inverse Document Frequency) for scoring document relevance.
- **Scalable**: Designed to handle large collections of documents.
- **Command-Line Interface**: Easy-to-use CLI for interacting with the search engine.

---

## How It Works

1. **Indexing Phase**:
   - The search engine reads a collection of documents and builds an **inverted index**.
   - The index maps each term to a list of documents where it appears.

2. **Query Processing**:
   - Processes user queries and retrieves relevant documents from the inverted index.
   - Supports Boolean operations (e.g., "cat AND dog").

3. **Ranking**:
   - Ranks documents based on **TF-IDF** scores, which measure the importance of a term in a document relative to the entire collection.

4. **Output**:
   - Displays the top-k most relevant documents for a given query.

---

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Plutonium17/COL106-Search-Engine.git
2. Navigate to the project directory:
   ```bash
   cd COL106-Search-Engine
3. Build the project using the provided Makefile:
   ```bash
   make


