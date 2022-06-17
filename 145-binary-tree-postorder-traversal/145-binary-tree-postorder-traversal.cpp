/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)   return ans;
        
        //Recursive solution
        /*postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        return ans;*/
        
        //Iterative solution
        stack<TreeNode*>st;
        TreeNode *curr = root, *temp;
        while(!st.empty() || curr){
            if(curr){
                st.push(curr);
                curr = curr->left;
            }
            else{
                temp = st.top()->right;
                if(!temp){
                   temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else    curr=temp;
            }
        }
        return ans;
    }
};