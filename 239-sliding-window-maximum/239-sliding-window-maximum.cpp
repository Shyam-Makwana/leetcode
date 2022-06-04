class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int l=0, r=0, n=size(nums);
        while(r<n){
            while(!dq.empty() && nums[dq.back()]<nums[r])   dq.pop_back();
            dq.push_back(r);
            if(l>dq.front())    dq.pop_front();
            if(r>=k-1){
                ans.push_back(nums[dq.front()]);
                l++;
            }
            r++;
        }
        return ans;
    }
};