class Solution {
public:
    unordered_map<char, string> mp { { '2', "abc"}, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" }, 
                                    { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" }};
    vector<string> result;
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)    return result;
        string curr = "";
        backTrack(digits, curr, 0, 0);
        return result;
    }
    
    void backTrack(string digits, string &curr, int i, int cnt){
        if(cnt==digits.size()){
            result.push_back(curr);
            return;
        }
        
        for(int j=i; j<digits.size(); j++){
            for(int k=0; k<mp[digits[j]].size(); k++){
                curr += mp[digits[j]][k];
                backTrack(digits, curr, j+1, cnt+1);
                curr.pop_back();
            }
        }
    }
};