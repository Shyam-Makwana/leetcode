class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*nth_element(begin(nums), begin(nums)+k-1, end(nums), greater<int>());
        return nums[k-1];*/
        
        k = nums.size() - k + 1;
        priority_queue<int> pq;
        for(int i: nums){
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};