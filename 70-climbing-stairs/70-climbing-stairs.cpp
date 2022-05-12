class Solution {
public:
    int climbStairs(int n) {
        int a=0, b=1;
        for(int i=1;i<n+1;i++){
            int t=b; 
            b+=a;
            a=t;
        }
        return b;
    }
};