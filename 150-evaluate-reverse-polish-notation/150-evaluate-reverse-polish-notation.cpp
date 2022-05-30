class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s: tokens){
            if(isdigit(s[s.size()-1]))  st.push(stoi(s));
            else{
                int b = st.top();   st.pop();
                int a = st.top();   st.pop();
                
                if(s=="+")  a += b;
                else if(s=="-")  a -= b;
                else if(s=="*")  a *= b;
                else    a /= b;
                
                st.push(a);
            }
        }
        return st.top();
    }
};