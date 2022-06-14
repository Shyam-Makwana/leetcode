class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        ans[0] = binSearch(nums, target, true);
        ans[1] = binSearch(nums, target, false);
        return ans;
    }
    
    int binSearch(vector<int> nums, int target, bool leftBias){
        int l = 0, r = size(nums)-1, i=-1;
        while(l<=r){
            int m = (l+r)/2;
            if(target>nums[m])  l = m + 1;
            else if(target<nums[m]) r = m - 1;
            else{
                i = m;
                if(leftBias)    r = m - 1;
                else l = m + 1;
            }
        }
        return i;
    }
};