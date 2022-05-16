class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1])    return -1;
        int ans = INT_MAX, level = 0;
        vector <pair<int,int>> dir {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        queue <pair<int,int>> q;
        q.push({0, 0});
        while(!q.empty()){
            int m = q.size();
            while(m--){
                pair <int,int> p = q.front();
                q.pop();
                int i = p.first ;
                int j = p.second;
                if(i<0 || j<0 || i>=n || j>=n || grid[i][j] == 1)
                    continue;
                if(i == n-1 && j == n-1){
                    ans = min(ans, level);
                    continue;
                }
                grid[i][j] = 1;
                for(auto k:dir){
                    int x = i + k.first ;
                    int y = j + k.second;
                    q.push({x, y});
                }
            }
            level ++;
        }
        return ans == INT_MAX ? -1 : ans+1;
    }
};