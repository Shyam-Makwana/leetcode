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
    
    TreeNode* invertTree(TreeNode* root) {
	    if(root==NULL)  return NULL;
					
		//Recursive DFS
        /*invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;*/

		//Iterative BFS
        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            swap(node->left, node->right);
            if(node->left)  stk.push(node->left);
            if(node->right) stk.push(node->right);
        }
        return root;
    }
};