class Solution {
public:
    static bool compare(vector<int> &A, vector<int> &B){
        int pt1 = A[0]*A[0] + A[1]*A[1];
        int pt2 = B[0]*B[0] + B[1]*B[1];
        return pt1 < pt2;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), compare);
        points.resize(k);
        return points;
        
        /*vector<vector<int>> ans;
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
        return ans;*/
    }
};