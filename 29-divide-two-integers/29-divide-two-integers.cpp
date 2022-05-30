class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)   return INT_MAX;
        long a = labs(dividend), b = labs(divisor), res = 0;
        while(a>=b){
            long temp = b, x = 0;
            while ((temp << 1) <= a) {
                temp <<= 1;
                x++;
            }
            a -= temp;
            res += 1<<x;
        }
        return (dividend>=0 == divisor>=0) ? res : -1*res;
    }
};