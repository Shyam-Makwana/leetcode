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
    int count = 0, ans = 0;
    
    /*void kthSmallest(TreeNode *root){
        if(root->left)  kthSmallest(root->left);
        if(--count == 0) {
            ans = root->val;
            return;  
        }
        if(root->right)  kthSmallest(root->right);
    }*/
    
    int kthSmallest(TreeNode* root, int k) {
        
        //Recursion In order
        /*count = k;
        kthSmallest(root);
        return ans;*/
        
        //Iterative In order
        stack<TreeNode*> st;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(--k == 0)  break;
            root = root->right;
        }
        return root->val;
    }
};