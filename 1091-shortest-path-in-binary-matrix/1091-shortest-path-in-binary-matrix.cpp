class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(grid[0][0] || grid[m-1][n-1])    return -1;
        queue<vector<int>> q;
        q.push({0,0,1});
        grid[0][0]=1;
        vector<vector<int>> v = { {1,1}, {0,1}, {1,0}, {0,-1}, {-1,0}, {-1,-1}, {-1,1}, {1,-1} };
        
        while(!q.empty()){
            vector<int> temp = q.front();
            q.pop();
            
            if(temp[0] == m-1 && temp[1] == n-1)    return temp[2];
            
            for(auto i:v){
                int x = temp[0] + i[0];
                int y = temp[1] + i[1];
                
                if(x>=0 && y>=0 && x<m && y<n && grid[x][y]==0){
                    grid[x][y]=1;
                    q.push({x,y,temp[2]+1});
                }
            }
        }
        return -1;
    }
};