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
    int maxDepth(TreeNode* root) {
        if(!root)   return 0;
        
        //Recursive DFS
        /*int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + max(left, right);*/
        
        //BFS
        /*int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode *t = q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right)    q.push(t->right);
            }
            level += 1;
        }
        return level;*/
        
        //Iterative DFS
        int level = 0;
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        while(!st.empty()){
            TreeNode *node = st.top().first;
            int depth = st.top().second;
            st.pop();
            level = max(level, depth);
            if(node->left) st.push({node->left, depth+1});
            if(node->right) st.push({node->right, depth+1});
        }
        return level;
    }
};