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
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({root->left, root->right});
        while(!st.empty()){
            TreeNode *left = st.top().first;
            TreeNode *right = st.top().second;
            st.pop();
            if(!left && !right) continue;
            if(!left || !right || left->val!=right->val) return false;
            
            st.push({left->left, right->right});
            st.push({left->right, right->left});
        }
        return true;
    }
};