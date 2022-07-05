class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for(auto i: st){
            if(st.find(i-1) == st.end()){
                int maxLen = 1;
                while(st.find(i + maxLen) != st.end()) maxLen++;
                ans = max(ans, maxLen);
            }
        }
        return ans;
    }
};