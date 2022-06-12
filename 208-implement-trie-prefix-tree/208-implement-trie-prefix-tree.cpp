struct Node{
    char c;
    int end;
    Node *child[26];
    Node(char ch){
        c = ch;
        end = 0;
        memset(child, NULL, sizeof(child));
    }
};

class Trie {
private:
    Node *root = new Node('/');
    
    Node* find(string word){
        Node *node = root;
        for(int i=0;i<size(word) && node;i++)   node = node->child[word[i]-'a'];
        return node;
    }
    
public:
    Trie(){
    }
    
    void insert(string word) {
        Node *node = root;
        for(char c:word){
            if(!node->child[c-'a']) node->child[c-'a'] = new Node(c); 
            node = node->child[c-'a'];
        }
        node->end += 1;
    }
    
    bool search(string word) {
        Node *ans = find(word);
        return ans && ans->end;
    }
    
    bool startsWith(string prefix) {
        return find(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */