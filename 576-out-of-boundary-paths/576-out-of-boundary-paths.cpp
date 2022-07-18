const int MOD = 1E9+7;
class Solution {
public:
    int dp[50][50][51];
    int m, n;
    int dir[5] = {0, 1, 0, -1, 0};
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m, this->n = n;
        memset(dp, -1, sizeof(dp));
        return dfs(startRow, startColumn, maxMove);
    }
    
    int dfs(int r, int c, int maxMove) {
        if(r<0 || c<0 || r==m || c==n)  return 1;
        if(maxMove == 0) return 0;
        if(dp[r][c][maxMove] != -1) return dp[r][c][maxMove];
        
        int ans = 0;
        for (int i = 0; i < 4; ++i)
            ans = (ans + dfs(r + dir[i], c + dir[i+1], maxMove - 1)) % MOD;
        return dp[r][c][maxMove] = ans;
    }
};