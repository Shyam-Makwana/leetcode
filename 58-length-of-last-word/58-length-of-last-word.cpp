class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size()-1, ans=0;
        while(s[n]==' ') n--;
        for(int i=n;i>=0;i--){
            if(s[i]==' ')   break;
            ans++;
        }
        return ans;
    }
};