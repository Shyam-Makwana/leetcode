class Solution {
public:
    int N;
    vector<string> ans;
    
    vector<string> generateParenthesis(int n) {
        N=n;
        addingpar(0,0, "");
        return ans;
    }
    
    void addingpar(int open, int close, string par){
        if(open == N && close == N) ans.push_back(par);
        if(open < N)  addingpar(open+1, close, par+"(");
        if(open > close)    addingpar(open, close+1, par+")");
    }
};