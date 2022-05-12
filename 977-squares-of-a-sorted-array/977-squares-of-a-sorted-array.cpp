class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        vector<int> ans(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            if(abs(nums[l])>abs(nums[r]))   ans[i] = nums[l] * nums[l++];
            else    ans[i] = nums[r] * nums[r--];
        }
        return ans;
    }
};