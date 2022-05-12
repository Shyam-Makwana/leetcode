class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(256,-1);
        int l=0, r=0, ans = 0;
        while(r<s.length()){
            if(v[s[r]]!=-1) l = max(v[s[r]]+1, l);
            ans = max(ans, r-l+1);
            v[s[r]]=r;
            r++;
            cout<<ans<<endl;
        }
        return ans;
    }
};