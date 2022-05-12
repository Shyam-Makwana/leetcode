class Solution {
public:
    void moveZeroes(vector<int>& A) {
        for(int i=0,j=0;j<A.size();j++) 
            if(A[j]!=0) swap(A[i++],A[j]);
    }
};