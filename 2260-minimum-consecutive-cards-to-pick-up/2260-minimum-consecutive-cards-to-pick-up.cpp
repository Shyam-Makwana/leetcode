class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        vector<int> v(1000001);
        int ans=INT_MAX;
        for(int i=0;i<cards.size();i++){
            if(v[cards[i]]) ans = min(ans, i-v[cards[i]]+2);
            v[cards[i]]=i+1;
        }
        return ans==INT_MAX ? -1 : ans;
    }
};