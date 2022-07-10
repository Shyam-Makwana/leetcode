class Solution {
public:
    int climbStairs(int n) {
        /*if(n<=2)    return n;
        int dp[n+1];
        dp[n] = dp[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            dp[i] = dp[i+1] + dp[i+2];
        }
        return dp[0];*/
        
        int one = 1, two = 1;
        for(int i=0; i<n-1; i++){
            int temp = one;
            one += two;
            two = temp;
        }
        return one;
    }
};