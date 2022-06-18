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
        nodes.push_back(root->val);
        return nodes;*/
        
        //Iterative solution
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            nodes.push_back(node->val);
            if(node->left)  st.push(node->left);
            if(node->right) st.push(node->right);
        }
        reverse(nodes.begin(), nodes.end());
        return nodes;
    }
};