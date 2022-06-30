class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int heavy1 = pq.top(); pq.pop();
            int heavy2 = pq.top(); pq.pop();
            if(heavy1 != heavy2)  pq.push(heavy1 - heavy2);
        }
        return pq.empty() ? 0 : pq.top();
    }
};