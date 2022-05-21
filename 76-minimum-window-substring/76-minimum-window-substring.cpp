class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length(), m=t.length();
        string subst = "";
        
        map<int,int> mp1, mp2;
        for(int i:t)    mp2[i]++;
        
        int have=0, need=mp2.size();
        int l=0, r=0, ansl=0, ansr=0, ans = INT_MAX;
        
        while(r<n){
            int c = s[r];
            mp1[c]++;
            
            if(mp2[c] && mp1[c]==mp2[c])    have++;
            while(have==need){
                if((r-l+1) < ans){
                    ansl = l, ansr = r;
                    ans = r-l+1;
                }
                mp1[s[l]]--;
                if(mp2[s[l]] && mp1[s[l]]<mp2[s[l]])    have--;
                l++;
            }
            r++;
        }
        if(ans!=INT_MAX)
            for(int i=ansl; i<ansr+1; i++)    subst+=s[i];
        return subst;
    }
};