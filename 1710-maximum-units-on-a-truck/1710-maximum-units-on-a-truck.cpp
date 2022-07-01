class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        
        int maxUnits = 0;
        for(auto box: boxTypes){
            int size = min(box[0], truckSize);
            truckSize -= size;
            maxUnits += (size*box[1]);
            if(!size)   break;
        }
        return maxUnits;
        
        /*int maxUnits = 0, size=0;
        priority_queue<pair<int, int>> pq;
        for(auto i: B)  pq.push({i[1], i[0]});
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
        return maxUnits;*/
    }
};