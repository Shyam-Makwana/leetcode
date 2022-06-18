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
    vector<int> nodes;
    
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)   return nodes;
        
        //Recursive solution
        /*postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        return nodes;*/
        
        //Iterative solution
        stack<TreeNode*> st;
        TreeNode *last = NULL;
        while (root || !st.empty()) {
            if (root) {
                st.push(root);
                root = root -> left;
            } 
            else {
                TreeNode *node = st.top();
                if (node -> right && last != node -> right) {
                    root = node -> right;
                } 
                else {
                    nodes.push_back(node -> val);
                    last = node;
                    st.pop();
                }
            }
        }
        return nodes;
    }
};