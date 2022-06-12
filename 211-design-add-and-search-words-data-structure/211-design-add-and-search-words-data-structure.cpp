struct Node{
    bool end;
    Node *child[26];
    Node(){
        end = false;
        memset(child, NULL, sizeof(child));
    }
};

class WordDictionary {
private:
    Node *root = new Node();
    
    void Trie_insert(string word){
        Node *curr = root;
        for(char c:word){
            if(!curr->child[c-'a'])   curr->child[c-'a'] = new Node();
            curr = curr->child[c-'a'];
        }
        curr->end = true;
    }
    
    bool Trie_search(const char *word, Node *node){
        for(int i=0; word[i] && node; ++i){
            if(word[i]!='.')    node = node->child[word[i]-'a'];
            else{
                Node *tmp = node;
                for(int j=0;j<26;++j){
                    node = tmp->child[j];
                    if(node && Trie_search(word+i+1, node)){
                        return true;
                    }
                }
            }
        }
        return node && node->end;
    }
    
public:
    WordDictionary() {
    }
    
    void addWord(string word) {
        Trie_insert(word);
    }
    
    bool search(string word) {
        return Trie_search(word.c_str(), root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */