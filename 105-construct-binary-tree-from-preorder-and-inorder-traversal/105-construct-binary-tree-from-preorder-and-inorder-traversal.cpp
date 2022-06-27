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
    int preorderIndex = 0;
    unordered_map<int, int> inorderIndexMap;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<size(inorder); i++)  inorderIndexMap[inorder[i]] = i;
        return build(preorder, 0, preorder.size() - 1);
    }
private:
    TreeNode* build(vector<int> preorder, int inStart, int inEnd) {
        if (inStart > inEnd)    return NULL;
        
        int rootValue = preorder[preorderIndex++];
        TreeNode *root = new TreeNode(rootValue);

        root->left = build(preorder, inStart, inorderIndexMap[rootValue] - 1);
        root->right = build(preorder, inorderIndexMap[rootValue] + 1, inEnd);
        
        return root;
    }
};