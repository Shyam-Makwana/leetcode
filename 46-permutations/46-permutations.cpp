class Solution {
public:
    vector<vector<int>> perm;
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<int> freq(size(nums));
        permute(nums, curr, freq);
        return perm;
    }
    
    void permute(vector<int>& nums, vector<int>& curr, vector<int> &freq) {
        if(size(curr)==size(nums)){
            perm.push_back(curr);
            return;
        }
        for(int i=0; i<size(nums); i++){
            if(!freq[i]){
                curr.push_back(nums[i]);
                freq[i] = 1;
                permute(nums, curr, freq);
                freq[i] = 0;
                curr.pop_back();
            }
        }
    }  
};