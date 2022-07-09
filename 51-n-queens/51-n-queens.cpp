class Solution {
public:
    vector<vector<string>> result;
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        dfs(n, 0, board);
        return result;
    }
    
    void dfs(int n, int row, vector<string> &board) {
        if(n==row){
            result.push_back(board);
            return;
        }
        
        for(int col=0; col<n; col++) {
            if(isValid(n, row, col, board)){
                board[row][col] = 'Q';
                dfs(n, row+1, board);
                board[row][col] = '.';
            }
        }
    }
    
    bool isValid(int n, int row, int col, vector<string> &board) {
        for(int i=0; i<row; i++) {
            if(board[i][col]=='Q')    return false;
        }
        
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if(board[i][j]=='Q')    return false;
        }
        
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++) {
            if(board[i][j]=='Q')    return false;
        }
        
        return true;
    }
};