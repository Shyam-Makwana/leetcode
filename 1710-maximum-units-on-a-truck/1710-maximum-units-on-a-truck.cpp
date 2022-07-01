class Solution {
public:
    int maximumUnits(vector<vector<int>>& B, int T) {
        int maxUnits = 0, size=0;
        priority_queue<pair<int, int>> pq;
        for(auto i: B){
            pq.push({i[1], i[0]});
        }
        while(!pq.empty()){
            auto i = pq.top(); pq.pop();
            if((size+i.second)<=T){
                maxUnits += (i.first*i.second);
                size += i.second;
            }
            else{
                maxUnits += ((T-size)*i.first);
                break;
            }
        }
        return maxUnits;
    }
};