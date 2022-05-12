class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0, ans=nums[0];
        for(int i:nums){
            sum+=i;    
            ans=max(ans,sum);
            if(sum<0)   sum=0;
        }
        return ans;
    }
};