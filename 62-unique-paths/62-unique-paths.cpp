class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return dfs(0, 0, dp);
    }
    
    int dfs(int m, int n, vector<vector<int>> &dp){
        int row = size(dp), col = size(dp[0]);
        if(m==row || n==col) return 0;
        if(dp[m][n])    return dp[m][n];
        if(m==row-1 && n==col-1)    return 1;

        dp[m][n] = dfs(m+1, n, dp) + dfs(m, n+1, dp);
        
        return dp[m][n];
    }
};