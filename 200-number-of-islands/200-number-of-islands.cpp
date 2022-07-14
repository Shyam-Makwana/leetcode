class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for(int i=0; i<size(grid); i++){
            for(int j=0; j<size(grid[0]); j++){
                if(grid[i][j]=='1'){
                    eraseIslands(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
    
    void eraseIslands(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i==size(grid) || j==size(grid[0]) || grid[i][j]=='0')  return;
        grid[i][j] = '0';
        
        eraseIslands(grid, i+1, j);
        eraseIslands(grid, i-1, j);
        eraseIslands(grid, i, j+1);
        eraseIslands(grid, i, j-1);
    }
};