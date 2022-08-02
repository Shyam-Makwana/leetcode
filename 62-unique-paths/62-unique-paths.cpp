class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return dfs(0, 0, dp);
    }
    
    int dfs(int m, int n, vector<vector<int>> &dp){
        int row = size(dp), col = size(dp[0]);
        
        if(m==row || n==col) return 0;  // out of bounds - invalid
        if(m==row-1 && n==col-1)    return 1;   // reached end - valid path
        if(dp[m][n])    return dp[m][n];    // directly return if already calculated
        
        return dp[m][n] = dfs(m+1, n, dp) + dfs(m, n+1, dp);    // store the result in dp[i][j] and then return
    }
};