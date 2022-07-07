class Solution {
public:
    vector<vector<int>> result;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> current;
		combinationSum(candidates, current, 0, target, 0);
		return result;
    }
    
    void combinationSum(vector<int>& candidates, vector<int>& current, int i, int target, int total){
        if(total==target){
            result.push_back(current);
            return;
        }
        if(total>target)    return;
        
        int prev = -1;
        for(int j=i; j<size(candidates); j++){
            if(candidates[j]==prev) continue;
            
            current.push_back(candidates[j]);
            combinationSum(candidates, current, j+1, target, total + candidates[j]);
            current.pop_back();
            
            prev = candidates[j];
        }
    }
};