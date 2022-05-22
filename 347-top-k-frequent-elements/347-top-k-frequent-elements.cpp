class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> m;
        for(int i:nums) m[i]++;
        
        multimap<int, int> mp;
        for(auto i:m)   mp.insert({i.second, i.first});
        
        for(auto it=mp.rbegin(); it!=mp.rend() && ans.size()<k; it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};