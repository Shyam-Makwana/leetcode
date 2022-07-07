class Solution {
    int row, col;
    string word;
public:
    bool dfs(vector<vector<char>>& board, int r, int c, int w){
        if(w==size(word))   return true;
        if(r<0 || c<0 || r>=row || c>=col || board[r][c]!=word[w])  return false;
        char ch = board[r][c];
        board[r][c] = '*';
        bool res = dfs(board, r+1, c, w+1) || dfs(board, r-1, c, w+1) || dfs(board, r, c+1, w+1) || dfs(board, r, c-1, w+1);
        board[r][c] = ch;
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string ww) {
        row = size(board), col = size(board[0]);
        word = ww;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(dfs(board, i, j, 0))  return true;
        return false;
    }
};