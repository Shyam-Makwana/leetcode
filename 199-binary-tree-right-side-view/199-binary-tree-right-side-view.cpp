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
    vector<int> nodes;
    
    void rightView(TreeNode *root, int level){
        if(!root)   return;
        
        if(nodes.size()==level) nodes.push_back(root->val);
        
        rightView(root->right, level + 1);
        rightView(root->left, level + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        //Recursion
        rightView(root, 0);
        
        /*queue<TreeNode *> q;
        
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
        }*/
        
        return nodes;
    }
};