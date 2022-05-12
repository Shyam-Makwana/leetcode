class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, ans=INT_MAX, sum=0, n=nums.size();
        for(int r=0;r<nums.size();r++){
            sum=sum+nums[r];
                while(sum>=target)  {
                    ans = min(ans, r-l+1);
                    sum-=nums[l];
                    l++;
                }
        }
        return ans==INT_MAX ? 0 : ans;
    }
};