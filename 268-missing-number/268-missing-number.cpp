class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0, i;
        for(i=0;i<nums.size();i++)  ans^=i^nums[i];
        return ans^i;
    }
};