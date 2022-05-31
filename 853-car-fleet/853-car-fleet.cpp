class Solution {
public:
    int carFleet(int target, vector<int>& P, vector<int>& S) {
        vector<pair<int, int>> pos_speed;
        for(int i=0;i<P.size();i++)  pos_speed.push_back({P[i], S[i]});
        sort(pos_speed.rbegin(), pos_speed.rend());
        
        stack<pair<int, float>> st;
        for(auto p: pos_speed){
            float time = (target-p.first)/(float)p.second;
            if(st.empty() || (time > st.top().second))  st.push({p.first, time});
        }
        
        return st.size();
    }
};