
A lightweight search engine implementation. This project demonstrates the core functionalities of a search engine, including indexing, query processing, and ranking of documents based on relevance. Built using C++, the search engine utilizes advanced data structures like hash maps, tries, and heaps to efficiently handle large datasets.

Table of Contents
Features

How It Works

Installation

Usage

File Structure

Technologies Used

Contributing

License

Features
Inverted Indexing: Efficiently maps terms to the documents containing them.

Query Processing: Supports single-word, multi-word, and Boolean queries (AND, OR).

Ranking: Implements TF-IDF (Term Frequency-Inverse Document Frequency) for scoring document relevance.

Scalable: Designed to handle large collections of documents.

Command-Line Interface: Easy-to-use CLI for interacting with the search engine.

How It Works
Indexing Phase:

The search engine reads a collection of documents and builds an inverted index.

The index maps each term to a list of documents where it appears.

Query Processing:

Processes user queries and retrieves relevant documents from the inverted index.

Supports Boolean operations (e.g., "cat AND dog").

Ranking:

Ranks documents based on TF-IDF scores, which measure the importance of a term in a document relative to the entire collection.

Output:

Displays the top-k most relevant documents for a given query.

Installation
Clone the repository:

bash
Copy
git clone https://github.com/Plutonium17/COL106-Search-Engine.git
Navigate to the project directory:

bash
Copy
cd COL106-Search-Engine
Build the project using the provided Makefile:

bash
Copy
make
Usage
Prepare your documents and queries:

Place your documents in a text file (e.g., data/documents.txt).

Add queries in another text file (e.g., data/queries.txt).

Run the search engine:

bash
Copy
./search_engine data/documents.txt data/queries.txt
View the results:

The search engine will output the top-k most relevant documents for each query.

File Structure
Copy
COL106-Search-Engine/
├── src/                  # Source code files
│   ├── indexer.cpp       # Code for building the inverted index
│   ├── query_processor.cpp # Code for processing queries
│   ├── ranking.cpp       # Code for ranking documents
│   └── main.cpp          # Entry point of the program
├── data/                 # Sample datasets and queries
│   ├── documents.txt     # Collection of documents
│   └── queries.txt       # Sample queries
├── tests/                # Test cases for validation
├── Makefile              # Build script
└── README.md             # Project documentation
Technologies Used
Programming Language: C++

Data Structures: Hash Maps, Tries, Heaps

Algorithms: TF-IDF, Boolean Query Processing

Build Tool: Makefile

Contributing
Contributions are welcome! If you'd like to contribute to this project, please follow these steps:

Fork the repository.

Create a new branch for your feature or bugfix:

bash
Copy
git checkout -b feature-name
Commit your changes:

bash
Copy
git commit -m "Add your message here"
Push to the branch:

bash
Copy
git push origin feature-name
Open a pull request.
