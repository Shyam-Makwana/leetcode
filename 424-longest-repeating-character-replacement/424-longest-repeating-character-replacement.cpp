class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0}, maxF = 0, l=0, ans=0;
        for(int r=0;r<s.length();r++){
            freq[s[r]-'A']++;
            maxF = max(maxF, freq[s[r]-'A']);
            
            while((r-l+1)-maxF > k) 
            {
                freq[s[l]-'A']--;
                l++;
            } 
            ans=max(ans, r-l+1);
        }
        return ans;
    }
};