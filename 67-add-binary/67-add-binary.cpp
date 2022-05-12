class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size(), carry=0;
        char aa, bb;
        if(m>n) swap(a,b);
        string ans = "";
        for(int i=a.size()-1, j=b.size()-1; i>=0; i--, j--){
            if(j<0)  bb='0';
            else bb=b[j];
            aa = a[i]; 
            if(aa=='1' && bb=='1'){
                if(carry==1)    ans+='1', carry=1;
                else    ans+='0', carry=1;
            }
            else{
                if(carry==1 && ((aa=='1' && bb=='0') || (aa=='0' && bb=='1')))  ans+='0', carry=1;
                else if(carry==0 && aa=='0' && bb=='0') ans+='0', carry=0;
                else    ans+='1', carry=0;
            }
        }
        if(carry==1)    ans+='1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};