class Solution {
public:
    vector<vector<int>> subset;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        subsets(nums, curr, 0);
        return subset;
    }
    
    void subsets(vector<int> &nums, vector<int> &curr, int i){
        if(i==size(nums)){
            subset.push_back(curr);
            return;
        }
        
        // decision to include nums[i]
        curr.push_back(nums[i]);
        subsets(nums, curr, i+1);
        
        // decision NOT to include nums[i]
        curr.pop_back(); 
        subsets(nums, curr, i+1);
    }
};