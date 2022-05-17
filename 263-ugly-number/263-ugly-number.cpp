class Solution {
public:
    bool isUgly(int num) {
        vector<int> v = {2,3,5};
        for(int i:v)
            while(num && num%i==0) num/=i;
        return num == 1;
    }
};