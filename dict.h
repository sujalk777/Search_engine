// Do NOT add any other includes
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
class SymNode
{
public:
    string key;
    int height;
    int count;
    SymNode *left;
    SymNode *right;
    SymNode *par;
    SymNode()
    {
        key = "";
        height = 1;
        count = 0;
        left = NULL;
        right = NULL;
        par = NULL;
    }
    SymNode(string k)
    {
        key = k;
        height = 1;
        count = 0;
        left = NULL;
        right = NULL;
        par = NULL;
    }
    void balanceheight(SymNode *root)
    {
        if (root != NULL)
        {
            int h = 1;
            if (root->right != NULL)
                h = max(h, root->right->height + 1);
            if (root->left != NULL)
                h = max(root->left->height + 1, h);
            root->height = h;
        }
    }
    SymNode *LeftLeftRotation()
    {
        SymNode *curr = left->par;
        SymNode *temp = left;
        left = temp->right;
        if (temp->right != NULL)
        {
            temp->right->par = curr;
        }
        temp->right = curr;
        temp->par = curr->par;
        curr->par = temp;
        if ((temp->par != NULL) && (curr->key < temp->par->key))
        {
            temp->par->left = temp;
        }
        else
        {
            if (temp->par != NULL)
                temp->par->right = temp;
        }
        curr = temp;
        balanceheight(curr->left);
        balanceheight(curr->right);
        balanceheight(curr);
        balanceheight(curr->par);
        return curr;
    }
    SymNode *RightRightRotation()
    {
        SymNode *curr = right->par;
        SymNode *temp = right;
        right = temp->left;
        if (temp->left != NULL)
        {
            temp->left->par = curr;
        }
        temp->left = curr;
        temp->par = curr->par;
        curr->par = temp;
        if ((temp->par != NULL) && (curr->key < temp->par->key))
        {
            temp->par->left = temp;
        }
        else
        {
            if (temp->par != NULL)
                temp->par->right = temp;
        }
        curr = temp;
        balanceheight(curr->left);
        balanceheight(curr->right);
        balanceheight(curr);
        balanceheight(curr->par);
        return curr;
    }
    SymNode *LeftRightRotation()
    {
        SymNode *curr = left->par;
        curr->left = curr->left->RightRightRotation();
        return curr->LeftLeftRotation();
    }
    SymNode *RightLeftRotation()
    {
        SymNode *curr = right->par;
        curr->right = curr->right->LeftLeftRotation();
        return curr->RightRightRotation();
    }
};
class SymbolTable
{
public:
    SymNode *root;
    int size;
    SymbolTable()
    {
        size = 0;
        root = NULL;
    }
    void deleter(SymNode *root)
    {
        if (root == NULL)
            return;
        else
        {
            deleter(root->left);
            deleter(root->right);
            delete root;
        }
    }
    void heightbalancer(SymNode *root)
    {
        if (root != NULL)
        {
            int h = 1;
            if (root->right != NULL)
                h = max(h, root->right->height + 1);
            if (root->left != NULL)
                h = max(h, root->left->height + 1);
            root->height = h;
        }
        else
            return;
    }
    SymNode *toinsert(SymNode *root, SymNode *parent, string k)
    {
        if (root == NULL)
        {
            root = new SymNode(k);
            root->height = 1;
            root->left = NULL;
            root->right = NULL;
            root->par = parent;
            root->key = k;
            root->count = 1;
        }
        else if (root->key > k)
        {
            root->left = toinsert(root->left, root, k);
            int h1 = 0;
            int h2 = 0;
            if (root->right != NULL)
                h2 = root->right->height;
            if (root->left != NULL)
                h1 = root->left->height;
            if (abs(h1 - h2) == 2)
            {
                if ((root->left != NULL) && (root->left->key > k))
                    root = root->LeftLeftRotation();
                else
                    root = root->LeftRightRotation();
            }
        }
        else
        {
            root->right = toinsert(root->right, root, k);
            int h1 = 0;
            int h2 = 0;
            if (root->right != NULL)
                h2 = root->right->height;
            if (root->left != NULL)
                h1 = root->left->height;
            if (abs(h1 - h2) == 2)
            {
                if ((root->right != NULL) && (root->right->key > k))
                    root = root->RightLeftRotation();
                else
                    root = root->RightRightRotation();
            }
        }
        heightbalancer(root);
        return root;
    }
    SymNode *balancer(SymNode *root)
    {
        int h1 = 0;
        int h2 = 0;
        if (root->left != NULL)
            h1 = root->left->height;
        if (root->right != NULL)
            h2 = root->right->height;
        if (abs(h1 - h2) == 2)
        {
            if (h2 > h1)
            {
                int righth1 = 0;
                int righth2 = 0;
                if (root->right->left != NULL)
                    righth1 = root->right->left->height;
                if (root->right->right != NULL)
                    righth2 = root->right->right->height;
                if (righth1 <= righth2)
                    root = root->RightRightRotation();
                else
                    root = root->RightLeftRotation();
            }
            else
            {
                int lefth1 = 0;
                int lefth2 = 0;
                if (root->left->left != NULL)
                    lefth1 = root->left->left->height;
                if (root->left->right != NULL)
                    lefth2 = root->left->right->height;
                if (lefth1 < lefth2)
                    root = root->LeftRightRotation();
                else
                    root = root->LeftLeftRotation();
            }
        }
        return root;
    }
    void insert(string k)
    {
        if (search(k) == 0)
        {
            root = toinsert(root, NULL, k);
            size++;
        }
        else
        {
            SymNode *temp = root;
            while (temp != NULL)
            {
                if (temp->key == k){
                    (temp->count)++;
                    return;
                }
                else if (temp->key < k) temp = temp->right;
                else temp = temp->left;
            }
        }
    }
    bool searcher(SymNode *root, string k)
    {
        SymNode *temp = root;
        while (temp != NULL)
        {
            if (temp->key == k)
                return true;
            else if (temp->key < k)
                temp = temp->right;
            else
                temp = temp->left;
        }
        return false;
    }
    int search(string k)
    {
        SymNode *temp = root;
        while (temp != NULL)
        {
            if (temp->key == k)
                return temp->count;
            else if (temp->key < k)
                temp = temp->right;
            else
                temp = temp->left;
        }
        return 0;
    }
    SymNode *get_root()
    {
        return root;
    }
    ~SymbolTable()
    {
        deleter(root);
    }
};
class Dict
{
public:
    Dict();

    ~Dict();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    int get_word_count(string word);

    void dump_dictionary(string filename);
    
    SymbolTable *dict;
    vector <SymbolTable*> roots;
};
