class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        for(int i=1;i<=numRows;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j<i;j++){
                temp.push_back((temp[j-1]*(i-j))/j);
            }
            v.push_back(temp);
        }
        return v;
    }
};