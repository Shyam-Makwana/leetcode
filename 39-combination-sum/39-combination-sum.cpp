class Solution {
public:
    vector<vector<int>> comb;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        combinationSum(candidates, temp, 0, target, 0);
        return comb;
    }
    
    void combinationSum(vector<int>& candidates, vector<int>& temp, int i, int target, int sum){
        if(sum==target) {
            comb.push_back(temp);
            return;
        }
        else if(sum>target || i>=size(candidates)) return;
        
        temp.push_back(candidates[i]);
        combinationSum(candidates, temp, i, target, sum + candidates[i]);
        
        temp.pop_back();
        combinationSum(candidates, temp, i+1, target, sum);
    }
};