class Solution {
public:
	vector<vector<int>> result;
	
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> current;
		combinationSum(candidates, current, 0, target, 0);
		return result;
	}
	
	void combinationSum(vector<int>& candidates, vector<int>& current, int i, int target, int total){
		if(total==target) {
			result.push_back(current);
			return;
		}
		else if(total>target) return;
		
        for(int j=i; j<size(candidates); j++){
            current.push_back(candidates[j]);
            combinationSum(candidates, current, j, target, total + candidates[j]);
            current.pop_back();
        }	
        
        /*current.push_back(candidates[i]);
		combinationSum(candidates, current, i, target, total + candidates[i]);
		
		current.pop_back();
		combinationSum(candidates, current, i+1, target, total);*/
	}
};