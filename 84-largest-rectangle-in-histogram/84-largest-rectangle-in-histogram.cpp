class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
        vector<pair<int,int>> st;
        int index, ans = 0;
        for(int i=0;i<size(H);i++){
            if(st.empty() || st.back().second<=H[i])  st.push_back({i, H[i]});
            else{
                while(!st.empty() && st.back().second>H[i]){
                    index = st.back().first;
                    ans = max(ans, (i-st.back().first)*st.back().second);
                    st.pop_back();
                }
                st.push_back({index, H[i]});
            }
        }
        for(auto &s: st)
        {
            int t = (size(H)-st.back().first)*(st.back().second);
            ans = max(ans, t);
            st.pop_back();
        }
        return ans;
    }
};