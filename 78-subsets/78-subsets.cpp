class Solution {
public:
    vector<vector<int>> subset;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        subsets(nums, curr, 0);
        return subset;
    }
    
    void subsets(vector<int> &nums, vector<int> &curr, int i){
        subset.push_back(curr);
        for(int j=i; j<size(nums); j++){
            curr.push_back(nums[j]);
            subsets(nums, curr, j+1);
            curr.pop_back(); 
        }
    }
};