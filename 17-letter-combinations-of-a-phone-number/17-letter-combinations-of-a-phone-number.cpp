class Solution {
public:
    unordered_map<char, string> mp { { '2', "abc"}, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" }, 
                                    { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" }};
    vector<string> result;
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty())    return result;
        string curr;
        backTrack(digits, curr, 0);
        return result;
    }
    
    void backTrack(string digits, string curr, int i){
        if(curr.size()==digits.size()){
            result.push_back(curr);
            return;
        }
        
        for(char c: mp[digits[i]]){
            backTrack(digits, curr + c, i+1);
        }
    }
};