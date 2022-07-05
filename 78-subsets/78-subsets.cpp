class Solution {
public:
    vector<vector<int>> subset;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        subsets(nums, sub, 0);
        return subset;
    }
    
    void subsets(vector<int>& nums, vector<int>& sub, int i){
        subset.push_back(sub);
        for(int j=i; j<size(nums); j++){
            sub.push_back(nums[j]);
            subsets(nums, sub, j+1);
            sub.pop_back();
        }      
    }
};