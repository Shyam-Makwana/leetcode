class Solution {
public:
    int N;
    vector<string> ans;
    string str;
    
    vector<string> generateParenthesis(int n) {
        N=n;
        genPar(0,0);
        return ans;
    }
    
    void genPar(int open, int close){
        if(open==N && close==N) ans.push_back(str);
        if(open<N){
            str+='(';
            genPar(open+1, close);
            str.pop_back();
        }
        if(open > close){
            str+=')';
            genPar(open, close+1);
            str.pop_back();
        }
    }
};