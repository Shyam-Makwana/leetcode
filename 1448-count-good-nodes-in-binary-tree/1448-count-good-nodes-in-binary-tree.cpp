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
    
    /*int totalGoodNodes = 0;
    
    void findGoodNodes(TreeNode *root, int value){
        if(!root)   return;
        if(root->val >= value){
            totalGoodNodes++;
            value = root->val;
        }
        findGoodNodes(root->left, value);
        findGoodNodes(root->right, value);
    }
    
    int goodNodes(TreeNode* root){
        findGoodNodes(root, INT_MIN);
        return totalGoodNodes;
    }*/
    
    int goodNodes(TreeNode* root, int value = INT_MIN) {
        return !root ? 0 : 
               ( goodNodes(root->left, max(value, root->val)) + 
                 goodNodes(root->right, max(value, root->val)) + 
                 (root->val>=value)
               ); 
    }
};