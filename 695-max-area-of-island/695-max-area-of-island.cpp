class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = size(grid), n = size(grid[0]), maxArea = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]) {
                    int area = 0;
                    dfs(grid, i, j, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int &area){
        if(i<0 || j<0 || i==size(grid) || j==size(grid[0]) || !grid[i][j])  return;
        
        area++;
        grid[i][j] = 0;
        dfs(grid, i+1, j, area);
        dfs(grid, i-1, j, area);
        dfs(grid, i, j+1, area);
        dfs(grid, i, j-1, area);
    }
};