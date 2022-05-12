class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for(int j=0, i=0; j<nums.size(); j++)
            if(nums[j]%2==0)
                swap(nums[i++],nums[j]);
        return nums;
    }
};