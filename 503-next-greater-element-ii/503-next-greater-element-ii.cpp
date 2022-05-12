class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        
        stack<int> st;
        
        
        for(int j=0;j<2*n;j++){
            while(!st.empty() && nums[j%n] > nums[st.top()]){
                res[st.top()]=nums[j%n];
                st.pop();
            }
            st.push(j%n);
        }
        return res;
    }
};