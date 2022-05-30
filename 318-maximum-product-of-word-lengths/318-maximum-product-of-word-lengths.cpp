class Solution {
public:
    int maxProduct(vector<string>& words){ 
        int ans = 0;
        vector<int> v;
        
        for(string s: words){
            int mask=0;
            for(int i:s){
                mask |= (1<<(i-'a'));
            }
            v.push_back(mask);
        }
        
        for(int i=0;i<size(words);i++){
            for(int j=i+1;j<size(words);j++){
                if((v[i] & v[j]) == 0)  ans = max(ans, (int) size(words[i]) * (int) size(words[j]));
            }
        }
        
        return ans;
    }
};