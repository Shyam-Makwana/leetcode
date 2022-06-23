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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> nodes;
        queue<TreeNode *> q;
        
        if(root)   q.push(root);
        
        while(!q.empty()){
            int size = q.size(), val;
            while(size--){
                TreeNode *node = q.front();
                q.pop();
                val = node->val;
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            nodes.push_back(val);
        }
        return nodes;
    }
};