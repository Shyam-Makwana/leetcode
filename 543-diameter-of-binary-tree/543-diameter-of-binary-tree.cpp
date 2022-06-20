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
    int getHeight(TreeNode *root, int &diameter){
        if(root==NULL)  return 0;
        int lh = getHeight(root->left, diameter);
        int rh = getHeight(root->right, diameter);
        diameter = max(diameter, lh+rh);
        return 1 + max(lh, rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        getHeight(root, diameter);
        return diameter;
    }
};