class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n){
            n -= 1;
            char tmp = 'A' + n % 26;
            res = tmp + res;
            n /= 26;
        }
        return res;
    }
};