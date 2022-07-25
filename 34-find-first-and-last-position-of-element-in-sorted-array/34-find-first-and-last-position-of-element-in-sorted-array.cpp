class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        ans[0] = binarySearch(nums, target, true);
        ans[1] = binarySearch(nums, target, false);
        return ans;
    }
    
    int binarySearch(vector<int>& nums, int target, bool leftValue) {
        int i = -1;
        int l = 0, r = size(nums)-1;
        while(l<=r) {
            int m = l + (r-l)/2;
            if(nums[m] < target)    l = m + 1;
            else if(nums[m] > target)   r = m - 1;
            else {
                i = m;
                if(leftValue)   r = m - 1;
                else l = m + 1;
            }
        }
        return i;
    }
};