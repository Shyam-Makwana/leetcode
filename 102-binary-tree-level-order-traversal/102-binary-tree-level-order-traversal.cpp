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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> nodes;
        if(root)   nodes.push(root);
        while(!nodes.empty()){
            int size = nodes.size();
            vector<int> v;
            while(size--){
                TreeNode *node = nodes.front();
                nodes.pop();
                v.push_back(node->val);
                if(node->left)  nodes.push(node->left);
                if(node->right) nodes.push(node->right);
            }
            result.push_back(v);
        }
        return result;
    }
};