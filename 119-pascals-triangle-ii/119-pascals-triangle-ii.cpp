class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> v(rowIndex+1);
        for(int i=0;i<=rowIndex;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j<=i;j++){
                long long t = temp[j-1];
                t*=(i-j+1);
                temp.push_back(t/j);
            }
            v[i] = temp;
        }
        return v[rowIndex];
    }
};