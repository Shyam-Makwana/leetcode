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
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)   return ans;
        
        //Recursive solution
        /*inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
        return ans;*/
        
        //Iterative Solution
        TreeNode *node = root;
        stack<TreeNode*> st;
        while(true){
            if(node){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty())  break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right; 
            }
        }
        return ans;
    }
};