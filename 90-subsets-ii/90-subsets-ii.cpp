class Solution {
public:
    vector<vector<int>> subset;
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        subsets(nums, curr, 0);
        return subset;
    }
    
    void subsets(vector<int> &nums, vector<int> &curr, int i){
        if(i==size(nums)){
            subset.push_back(curr);
            return;
        }
        
        curr.push_back(nums[i]);
        subsets(nums, curr, i+1);
        
        while((i+1)<size(nums) && nums[i]==nums[i+1])   i++;
        
        curr.pop_back();
        subsets(nums, curr, i+1);
    }
};