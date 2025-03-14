// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include "Node.h"
using namespace std;

class LinkedList{
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~LinkedList(){
        Node* temp = head;
        while (temp != nullptr){
            Node* temp2 = temp;
            temp = temp->right;
            delete temp2;
        }
    }
    void insert(Node* node){
        if (head == nullptr){
            head = node;
            tail = node;
        }
        else{
            tail->right = node;
            node->left = tail;
            tail = node;
        }
        size++;
    }
};
class SearchEngine {
private:
    // You can add attributes/helper functions here

public: 
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    SearchEngine();

    ~SearchEngine();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    Node* search(string pattern, int& n_matches);

    /* -----------------------------------------*/
    vector<vector<string>> tot;
    vector <LinkedList*> v;
};
