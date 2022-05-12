class Solution {
public:
    int mySqrt(int x) {
        if(x==1)    return 1;
        int l=1, r=x/2, ans;
        while(l<=r){
            long long mid = (l+r)/2;
            long long t = mid*mid;
            if(t==x)    return mid;
            else if(t<x)    l=mid+1;
            else    r = mid-1;
        }
        return l-1;
    }
};