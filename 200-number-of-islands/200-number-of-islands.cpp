class Solution {
public:
    //BFS Solution
    int numIslands(vector<vector<char>>& grid) {
        int n = size(grid), m = size(grid[0]), islands = 0, dir[] = {0, 1, 0, -1, 0};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    islands++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';
                    while(!q.empty()){
                        pair<int, int> p = q.front();
                        q.pop();
                        for(int k=0; k<4; k++){
                            int r = p.first + dir[k], c = p.second + dir[k+1];
                            if(r<0 || c<0 || r==n || c==m || grid[r][c]=='0')   continue;
                            q.push({r, c});
                            grid[r][c] = '0';
                        }
                    }
                }
            }
        }
        
        return islands;
    }
    
    //DFS Solution
    /*int numIslands(vector<vector<char>>& grid) {
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
    }*/
};