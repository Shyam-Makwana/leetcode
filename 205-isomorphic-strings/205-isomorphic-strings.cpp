class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int ss[256] = {}, tt[256] = {};
        for (int i = 0; i < s.size(); ++i) {
            if (ss[s[i]] != tt[t[i]]) return false;
            ss[s[i]] = i + 1;
            tt[t[i]] = i + 1;
        }
        return true;
    }
};