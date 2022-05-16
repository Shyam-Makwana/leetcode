class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> mp;
        while(!mp[n]){
            mp[n] = true;
            int sum=0;
            while(n){
                sum+=(n%10)*(n%10);
                n/=10;
            }
            if(sum==1)  return true;
            n=sum;
            cout<<sum<<' ';
        }
        return false;
    }
};