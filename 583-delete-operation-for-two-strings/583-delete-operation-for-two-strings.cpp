class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = size(word1), m = size(word2);
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0)    dp[i][j] = i+j;
                else if(word1[i-1]==word2[j-1])  dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};