class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int column = matrix[0].size(), row = matrix.size();
        int l=0, r=row*column-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int row = mid/column;
            int col = mid%column;
            if(matrix[row][col] == target)    return true;
            else if (matrix[row][col]<target)   l = mid+1;
            else r = mid-1;
        }
        return false;
    }
};