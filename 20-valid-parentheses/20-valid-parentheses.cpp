class Solution {
public:
    bool isValid(string s) {
        bool flag = true;
        stack<char> st;
        for(char c:s){
            if(st.empty() || c=='(' || c=='{' || c=='[')  st.push(c);
            else{
                if((st.top()=='(' && c==')') || (st.top()=='{' && c=='}') || (st.top()=='[' && c==']')){
                    st.pop();
                }
                else{
                    flag = false;
                    break;
                }
            }
        }
        if(flag && st.empty())    return true;
        return false;
    }
};