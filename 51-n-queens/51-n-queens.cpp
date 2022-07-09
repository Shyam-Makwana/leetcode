class Solution {
public:
    vector<vector<string>> result;
    unordered_set<int> col, posDiag, negDiag;
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        dfs(n, 0, board);
        return result;
    }
    
    void dfs(int n, int r, vector<string> &board) {
        if(n==r){
            result.push_back(board);
            return;
        }
        
        for(int c=0; c<n; c++) {
            if(col.find(c)!=col.end() || posDiag.find(r+c)!=posDiag.end() || negDiag.find(r-c)!=negDiag.end())  continue;
        
            board[r][c] = 'Q';
            col.insert(c);
            posDiag.insert(r+c);
            negDiag.insert(r-c);
            
            dfs(n, r+1, board);
            
            col.erase(c);
            posDiag.erase(r+c);
            negDiag.erase(r-c);
            board[r][c] = '.';
        }
    }
};