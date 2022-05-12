class Solution {
public:
    int strStr(string h, string n) {
        if(n.length()==0)   return 0;
        for(int i=0;i<h.length();i++){
            int j=0, k=i;
            while(j<n.length() && h[k]==n[j])   k++, j++;
            if(j==n.length())   return i;
        }
        return -1;
    }
};