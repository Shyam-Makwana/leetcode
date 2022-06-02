class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> trans_mat(col, vector<int>(row, 0));
        for (int j = 0; j < col; j++)
            for (int i = 0; i < row; i++)
                trans_mat[j][i] = matrix[i][j];
        return trans_mat;
    }
};