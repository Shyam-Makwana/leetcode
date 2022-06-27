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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart = 0;
        return build(preorder, inorder, preStart, 0, inorder.size() - 1);
    }
private:
    TreeNode* build(vector<int> preorder, vector<int> inorder, int &preStart, int inStart, int inEnd) {
        if (inStart > inEnd)    return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int pivot = inStart;
        while(preorder[preStart] != inorder[pivot])  pivot++;
        
        preStart++;
        root->left = build(preorder, inorder, preStart, inStart, pivot - 1);
        root->right = build(preorder, inorder, preStart, pivot + 1, inEnd);
        
        return root;
    }
};