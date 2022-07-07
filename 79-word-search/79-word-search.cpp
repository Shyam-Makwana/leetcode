class Solution {
public:
    int row, col;
    bool exist(vector<vector<char>>& board, string word) {
        row = size(board), col = size(board[0]);
        int find = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(exist(board, word, find, i, j)) return true;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word, int find, int i, int j){
        if(i<0 || j<0 || i==row || j==col || board[i][j]=='*' || board[i][j]!=word[find]) return false;
        if(find==size(word)-1)  return true;
        
        char c = board[i][j];
        board[i][j] = '*';
        bool ans = exist(board, word, find+1, i+1, j) || exist(board, word, find+1, i-1, j) ||
                   exist(board, word, find+1, i, j+1) || exist(board, word, find+1, i, j-1);
        
        board[i][j] = c;
        return ans;
    }
};