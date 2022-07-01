class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*nth_element(begin(nums), begin(nums)+k-1, end(nums), greater<int>());
        return nums[k-1];*/
        
        /*partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        return nums[k - 1];*/

        /*priority_queue<int, vector<int>, greater<int>> pq;
        for(int i: nums){
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();*/
        
        int n = size(nums), l = 0, r = n-1;
        
        while(true){
            int pivot = partition(nums, l , r);
            if(pivot == n - k)  return nums[pivot];
            else if(pivot < n-k)    l = pivot + 1;
            else r = pivot - 1;
        }
    }
    
    int partition(vector<int> &nums, int l, int r){
        int pivot = l;
        for(int i=l; i<r; i++){
            if(nums[i]<=nums[r]){
                swap(nums[i], nums[pivot]);
                pivot++;
            }
        }
        swap(nums[pivot], nums[r]);
        return pivot;
    }
};