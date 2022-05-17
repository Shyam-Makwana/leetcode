class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            if(!s.insert(nums[i]).second)   return true;
            s.insert(nums[i]);
            if(s.size() > k)    s.erase(nums[i-k]);
        }
        return false;
    }
};