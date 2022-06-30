class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i: stones)  pq.push(i);
        
        while(pq.size()!=1 && pq.size()!=0) {
            int heavy1 = pq.top(); pq.pop();
            int heavy2 = pq.top(); pq.pop();
            if(heavy1!=heavy2)  pq.push(heavy1-heavy2);
        }
        return pq.size() ? pq.top() : 0;
    }
};