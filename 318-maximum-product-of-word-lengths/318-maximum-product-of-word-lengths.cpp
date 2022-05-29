class Solution {
public:
    
    bool checkCommon(bitset<26> &v1, bitset<26> &v2){
        for(int i=0;i<26;i++)   if(v1[i] && v2[i])  return false;
        return true;
    }
    
    int maxProduct(vector<string>& words){ 
        int n = words.size(), ans = 0; 
        vector<bitset<26>> vec(n); 
        
        for(int i=0;i<n;i++){
            for(auto c: words[i])    vec[i][c-'a'] = 1;
        
            for(int j=0;j<i;j++){
                if(checkCommon(vec[i], vec[j])) 
                    ans =  max(ans, (int) size(words[i]) * (int) size(words[j]));
            }
        }
        return ans;
    }
};