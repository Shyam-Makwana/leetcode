class Solution {
 public:
     int subtractProductAndSum(int n) {
        int digits_sum = 0;
        int digits_product = 1;
        while ( n > 0) {
            int last_digit =  n % 10 ;
            digits_sum = digits_sum + last_digit;
            digits_product = digits_product * last_digit;
            n = n/ 10;
        }
        return digits_product - digits_sum;
    }
};
