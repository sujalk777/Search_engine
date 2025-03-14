// Do NOT add any other includes
#include "search.h"
long long powermodulo2(long long base,long long exponent,long long modulo){
    long long ans =1;
    if (base<0) base+=modulo;
    while (exponent){
        if (exponent&1) ans=(ans*base)%modulo;
        base=(base*base)%modulo;
        exponent/=2;
    }
    return ans;
}
const long long p = 31; 
const long long m = 1e9 + 7;
SearchEngine::SearchEngine(){
    // Implement your function here 
}

SearchEngine::~SearchEngine(){
    // Implement your function here
    for (int i=0;i<v.size();i++) delete v[i];
    v.clear();  
    tot.clear();
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    // Implement your function here
    for (int i=0;i<sentence.size();i++){
        sentence[i] = tolower(sentence[i]);
    }
    vector<string>temp={to_string(book_code), to_string(page), to_string(paragraph), to_string(sentence_no), sentence};
    tot.push_back(temp);
}

Node* SearchEngine::search(string pattern, int& n_matches){
    LinkedList* occurrences = new LinkedList();
    for (int i=0;i<pattern.size();i++){
        pattern[i] = tolower(pattern[i]);
    }
    v.push_back(occurrences);
    n_matches = 0;
    int s = pattern.size();
    for (int j = 0; j < tot.size(); j++){
            int t = tot[j][4].size();
            vector<long long> h(t + 1, 0); 
            for (int i = 0; i < t; i++){
                h[i+1] = (h[i] + (tot[j][4][i] - 'a' + 1) * powermodulo2(p,i,m)) % m;
            } 
            long long count = 0; 
            for (int i = 0; i < s; i++){
                count = (count + (pattern[i] - 'a' + 1) * powermodulo2(p,i,m)) % m; 
            }
            for (int i = 0; i + s < t + 1; i++) {
                long long cur_h = (h[i+s] + m - h[i]) % m;
                if (cur_h == (count * powermodulo2(p,i,m)) % m){
                    bool ok = true;
                    if(pattern==tot[j][4]){
                        ok=false;
                    }
                    if(ok){
                        Node* new_node = new Node();
                        new_node->offset = i;
                        new_node->sentence_no = stoi(tot[j][3]);
                        new_node->paragraph = stoi(tot[j][2]);
                        new_node->page = stoi(tot[j][1]);
                        new_node->book_code = stoi(tot[j][0]);
                        occurrences->insert(new_node);
                        n_matches++;
                    }
                }
            }
    }
    return occurrences->head;
}

int main(){
    SearchEngine* se = new SearchEngine();
    se->insert_sentence(1, 1, 1, 1, "Hello World");
    se->insert_sentence(1, 1, 1, 2, "Hello World");
    se->insert_sentence(1, 1, 1, 3, "Hello World");
    se->insert_sentence(1, 1, 1, 4, "Hello World");
    se->insert_sentence(1, 1, 1, 5, "Hello World");
    se->insert_sentence(1, 1, 1, 6, "Hello World");
    se->insert_sentence(1, 1, 1, 7, "Hello World");
    se->insert_sentence(1, 1, 1, 8, "Hello World");
    se->insert_sentence(1, 1, 1, 9, "Hello World");
    se->insert_sentence(1, 1, 1, 10, "Hello World");
    se->insert_sentence(1, 1, 1, 11, "Hello World");
    se->insert_sentence(1, 1, 1, 12, "Hello World");
    se->insert_sentence(1, 1, 1, 13, "Hello World");
    se->insert_sentence(1, 1, 1, 14, "Hello World");
    se->insert_sentence(1, 1, 1, 15, "Hello World");
    se->insert_sentence(1, 1, 1, 16, "Hello World");
    se->insert_sentence(1, 1, 1, 17, "Hello World");
    se->insert_sentence(1, 1, 1, 18, "Hello World");
    se->insert_sentence(1, 1, 1, 19, "Hello World");
    se->search("Hello World", 0);
    return 0;
}
