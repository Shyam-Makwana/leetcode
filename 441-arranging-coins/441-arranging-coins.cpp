class Solution {
public:
    int arrangeCoins(int n) {
        long long t=1;
        while((t*t+t)<=((long long)2*n)) t++;
        return --t;
    }
};