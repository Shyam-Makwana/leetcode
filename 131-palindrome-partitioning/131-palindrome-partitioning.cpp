class Solution {
public:
    vector<vector<string>> result;
    
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        partition(curr, s, 0);
        return result;
    }
    
    void partition(vector<string> &curr, string s, int i){
        if(i==s.size()){
            result.push_back(curr);
            return;
        }
        
        for(int j=i; j<s.size(); j++){
            string t = s.substr(i, j+1-i);
            if(isPal(t)){
                curr.push_back(t);
                partition(curr, s, j+1);
                curr.pop_back();
            }
        }
    }
    
    bool isPal(string t){
        int l=0, r=t.size()-1;
        while(l<r){
            if(t[l]!=t[r])  return false;
            l++;
            r--;
        }
        return true;
    }
};