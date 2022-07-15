class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = size(grid), n = size(grid[0]), maxArea = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i==size(grid) || j==size(grid[0]) || !grid[i][j])  return 0;
        
        grid[i][j] = 0;
        
        return (1 + dfs(grid, i+1, j) +
                    dfs(grid, i-1, j) +
                    dfs(grid, i, j+1) +
                    dfs(grid, i, j-1) );
    }
};