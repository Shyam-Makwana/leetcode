class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int,int>>st;
        vector<int>ans(size(T));
        
        for(int i=0;i<size(T);i++){
            while(!st.empty() && st.top().first < T[i]){
                ans[st.top().second] = i-st.top().second;
                st.pop(); 
            }
            st.push({T[i], i});
        }
        return ans;
    }
};