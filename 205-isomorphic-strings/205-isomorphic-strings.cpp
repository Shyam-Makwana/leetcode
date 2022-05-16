class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int, int> ss, tt;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(ss[s[i]-'a'] == tt[t[i]-'a'])    {
                ss[s[i]-'a'] = i+1;
                tt[t[i]-'a'] = i+1;
            }
            else return false;
        }
        return true;
    }
};