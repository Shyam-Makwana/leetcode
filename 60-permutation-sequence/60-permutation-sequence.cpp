class Solution {
public:
    string getPermutation(int n, int k)
    {
        string ans="";
        vector<int>fact(n,1);
        vector<int>digit(n,1);
        for(int i=1;i<n;i++)
        {
            fact[i]=fact[i-1]*(i+1);
            digit[i]=i+1;
        }
        while (ans.size()<(n-1))
         {
            int repeat=fact[fact.size()-2];
            int block=(k-1)/repeat;
            ans+=to_string(digit[block]);
            cout<<digit[block];
            fact.pop_back();
            digit.erase(digit.begin()+block);
            k=k%repeat;
            if(k==0)
            {
                for(int i=digit.size()-1;i>=0;i--)
                {
                    ans+=to_string(digit[i]);
                }
            }
        }
        if(ans.size()<n)    ans+=to_string(digit[0]);
        return ans;
    }
};