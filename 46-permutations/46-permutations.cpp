class Solution {
public:
    vector<vector<int>> perm;
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        permute(nums, curr);
        return perm;
    }
    
    void permute(vector<int>& nums, vector<int>& curr) {
        if(size(curr)==size(nums)){
            perm.push_back(curr);
            return;
        }
        for(int i=0; i<size(nums); i++){
            if(find(curr.begin(), curr.end(), nums[i]) != curr.end())  continue;
            curr.push_back(nums[i]);
            permute(nums, curr);
            curr.pop_back();
        }
    }  
};