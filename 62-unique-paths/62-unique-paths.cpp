class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return dfs(0, 0, grid, dp);
    }
    
    int dfs(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp){
        int row = size(grid), col = size(grid[0]);
        if(m<0 || n<0 || m==row || n==col || grid[m][n]) return 0;
        if(dp[m][n])    return dp[m][n];
        if(m==row-1 && n==col-1)    return 1;
        
        grid[m][n] = 1;
        dp[m][n] = dfs(m+1, n, grid, dp) + dfs(m, n+1, grid, dp);
        grid[m][n] = 0;
        
        return dp[m][n];
    }
};