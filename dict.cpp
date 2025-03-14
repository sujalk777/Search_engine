// Do NOT add any other includescount
#include "dict.h"
long long powermodulo(long long base,long long exponent,long long modulo){
    long long ans =1;
    if (base<0) base+=modulo;
    while (exponent){
        if (exponent&1) ans=(ans*base)%modulo;
        base=(base*base)%modulo;
        exponent/=2;
    }
    return ans;
}
long long hasher(string s){
    long long x = 0;
    for (int i=0;i<s.size();i++){
        x += abs(int(s[i])-97)*powermodulo(17,i,10007);
        x%=10007;
    }
    return x;
}
Dict::Dict()
{
    // Implement your function here
    for (int i=0;i<10007;i++){
        SymbolTable* a = new SymbolTable();
        roots.push_back(a);
    }
}
Dict::~Dict()
{
    // Implement your function here
    for (int i=0;i<10007;i++){
        delete roots[i];
    }
    roots.clear();
}
void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence)
{
    // Implement your function here
    string word = "";
    vector<char> forbidden = {' ', '.',',','-',':','!','\"','\'','(',')','[',']','?',';','@'};
    // for (int i=32;i<48;i++) forbidden.push_back(char(i));
    // for (int i=58;i<65;i++) forbidden.push_back(char(i));
    // for (int i=91;i<97;i++) forbidden.push_back(char(i));
    // for (int i=123;i<127;i++) forbidden.push_back(char(i));
    for (int i = 0; i < sentence.size(); i++)
    {
        sentence[i] = tolower(sentence[i]);
        bool b = false;
        for (int j = 0; j < forbidden.size(); j++){
            if (forbidden[j]==(sentence[i])) {
                b = true;
                break;
            }
        }
        if (b)
        {
            if (word != "")
            {
                long long y = hasher(word);
                (roots[y])->insert(word);
                word = "";
            }
        }
        else
        {
            word += sentence[i];
        }
    }
    if(word != "") {
        long long y = hasher(word);
        roots[y]->insert(word);
    }
    return;
}

int Dict::get_word_count(string word)
{
    // Implement your function here
    for (int i=0; i<word.size();i++) word[i] = tolower(word[i]);
    long long y = hasher(word);
    return roots[y]->search(word);
}
void inorder(SymNode* root, vector<vector<string> >& ans){
    if(root == NULL) return;
    inorder(root->left,ans);
    ans.push_back({root->key,to_string(root->count)});
    inorder(root->right,ans);
}

void Dict::dump_dictionary(string filename)
{
    // Implement your function here
    ofstream myfile;
    myfile.open(filename);
    vector<vector<string>> ans;
    for (int i=0;i<roots.size();i++) inorder(roots[i]->get_root(),ans);
    for(int i = 0; i < ans.size(); i++){
        myfile << ans[i][0] << ", " << ans[i][1] << endl;
    }
}
