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
    int findMaxi(TreeNode *root, int &maxi){
        if(!root)   return 0;
        
        int leftSum = findMaxi(root->left, maxi);
        int rightSum = findMaxi(root->right, maxi);
        
        if(leftSum < 0)    leftSum = 0;
        if(rightSum < 0)    rightSum = 0;
        
        maxi = max(maxi, root->val + leftSum + rightSum);
        return root->val + max(leftSum, rightSum);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findMaxi(root, maxi);
        return maxi;
    }
};