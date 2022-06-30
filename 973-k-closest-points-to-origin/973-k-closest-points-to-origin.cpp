class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<float, vector<int>>> pq;
        for(auto i: points){
            int x = i[0];
            int y = i[1];
            int ans = (x*x) + (y*y);
            pq.push({-sqrt(ans*1.0), i});
        }
        while(k--){
            auto v = pq.top().second;
            pq.pop();
            ans.push_back(v);
        }
        return ans;
    }
};