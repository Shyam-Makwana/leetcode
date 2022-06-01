class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
        vector<pair<int,int>> st;
        int index, ans = 0, N = size(H);
        for(int i=0;i<size(H);i++){
            index = i;
            while(!st.empty() && st.back().second>H[i]){
                index = st.back().first;
                ans = max(ans, (i-st.back().first)*st.back().second);
                st.pop_back();
            }
            st.push_back({index, H[i]});
        }
        while(!st.empty())
        {
            ans = max(ans, (N-st.back().first)*st.back().second);
            st.pop_back();
        }
        return ans;
    }
};