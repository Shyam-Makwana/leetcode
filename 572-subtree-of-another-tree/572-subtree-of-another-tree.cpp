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
    bool isSameTree(TreeNode *p, TreeNode *q){
        if(!p || !q)  return p==q;
        
        return (p->val==q->val && 
                isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right)); 
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot)    return true;
        if(!root)   return false;
        
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode *node = st.top();
            st.pop();
            if(node->val==subRoot->val && isSameTree(node, subRoot))    return true;
            if(node->right) st.push(node->right);
            if(node->left)  st.push(node->left);
        }
        return false;
    }
};