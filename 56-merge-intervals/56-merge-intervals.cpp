class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        vector<int> temp = v[0];
        for(auto i: v){
            if(temp[1]>=i[0]){
                temp[1]=max(temp[1], i[1]);
            }
            else{
                ans.push_back(temp);
                temp = i;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};