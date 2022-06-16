struct Node{
    bool end = false;
    Node *child[26] = {NULL};
    string word = "";
};

class Solution {
public:
    Node *root;
    vector<string> ans;
    int row, col;
    
    Solution() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(char c:word){
            if(!node->child[c-'a']) node->child[c-'a'] = new Node(); 
            node = node->child[c-'a'];
        }
        node->end = true;
        node->word = word;
    }
    
    void dfs(vector<vector<char>>& board, int r, int c, Node *curr){
        if(r<0 || c<0 || r==row || c==col || board[r][c]=='*' || !curr->child[board[r][c]-'a']) return;
        
        curr = curr->child[board[r][c]-'a'];
        if(curr->end){
            ans.push_back(curr->word);
            curr->end = false;
        }
        
        char ch = board[r][c];
        board[r][c] = '*';
        
        dfs(board, r+1, c, curr);
        dfs(board, r-1, c, curr);
        dfs(board, r, c+1, curr);
        dfs(board, r, c-1, curr);
        
        board[r][c] = ch;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        row = size(board), col = size(board[0]);
        
        for(string s: words)    insert(s);
        
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                dfs(board, i, j, root);
        return ans;   
    }
};