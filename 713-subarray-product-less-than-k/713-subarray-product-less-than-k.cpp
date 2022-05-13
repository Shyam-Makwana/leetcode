class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0, prod=1;
        for(int i=0, j=0;i<nums.size();i++){
            prod*=nums[i];
            while(j<=i && prod>=k)  prod/=nums[j++];
            ans+=i-j+1;
        }
        return ans;
    }
};