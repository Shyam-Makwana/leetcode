class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        set<int> s(v.begin(), v.end());
        int ans=0;
        for(int i:s){
            if(s.find(i-1)==s.end()){
                int len=0;
                while(s.find(i+len)!=s.end())   len++;
                ans = max(ans, len);
            }
        }
        return ans;
    }
};