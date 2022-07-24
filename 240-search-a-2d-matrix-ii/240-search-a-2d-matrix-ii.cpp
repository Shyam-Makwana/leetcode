class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = size(matrix), n = size(matrix[0]), r = 0, c = n-1;
        while(r < m && c >= 0) {
            if(matrix[r][c] == target)  return true;
            target < matrix[r][c] ? c-- : r++;
        }
        return false;
    }
};