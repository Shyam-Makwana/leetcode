/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    vector<string> nodeValue;

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        serialize(root, s);
        cout<<s<<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index=0;
        stringstream s(data);
        while (getline(s, data, ','))   nodeValue.push_back(data);
        
        return deserialize(index);
    }

private:
    TreeNode* deserialize(int &index){
        string value = nodeValue[index++];
        if(value=="N")  return NULL;
        
        TreeNode *root = new TreeNode(stoi(value));
        root->left = deserialize(index);
        root->right = deserialize(index);
        
        return root;
    }
    
    void serialize(TreeNode *root, string &s){
        if(root){
            s += to_string(root->val) + ",";
            serialize(root->left, s);
            serialize(root->right, s);
        }
        else    s+="N,";
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));