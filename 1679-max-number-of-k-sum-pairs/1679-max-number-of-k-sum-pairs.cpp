class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int, int> m;
        for(auto i:nums){
            int t = k-i;
            if(m[t]>0)   m[t]--, ans++;
            else    m[i]++;
        }
        return ans;
    }
};