class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                if(ans.size()!=0)   v.push_back(ans);
                ans="";
                continue;
            }
            ans+=s[i];
        }
        if(ans.size()!=0)   v.push_back(ans);
        string finalans="";
        auto it=v.rbegin();
        int i=0;
        for(it=v.rbegin();it!=v.rend();it++)
        {
            if(i==v.size()-1)   finalans+=*it;
            else finalans+=*it+" ";
            i++;
        }
        return finalans;
    }
};