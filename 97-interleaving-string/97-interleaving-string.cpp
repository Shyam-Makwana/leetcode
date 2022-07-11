class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if(len3 != (len1 + len2))    return false;
        
        vector<vector<bool>> dp(len1+1, vector<bool> (len2+1)); 
        dp[len1][len2] = true;
        
        for(int i=len1; i>=0; i--){
            for(int j=len2; j>=0; j--){
                if(i<len1 && s1[i]==s3[i+j] && dp[i+1][j])  dp[i][j] = true;
                if(j<len2 && s2[j]==s3[i+j] && dp[i][j+1])  dp[i][j] = true;
            }
        }
        return dp[0][0];
    }
};