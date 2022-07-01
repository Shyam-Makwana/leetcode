class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>> pq;
        int i=0;
        for(auto pt: points){
            int ans = (pt[0]*pt[0]) + (pt[1]*pt[1]);
            pq.push({ans, i++});
            if(pq.size()>k) pq.pop();
        }
        while(k--){
            int i = pq.top().second;
            pq.pop();
            ans.push_back(points[i]);
        }
        return ans;
    }
};