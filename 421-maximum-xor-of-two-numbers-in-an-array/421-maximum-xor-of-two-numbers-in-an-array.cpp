struct Node{
    Node *child[2] = {NULL};
};

class Solution {
private:
    Node *root;
public:
    Solution(){
        root = new Node();
    }
    
    void insert(int n){
        Node *curr = root;
        for(int i=31; i>=0; i--){
            int bit = (n>>i) & 1;
            if(!curr->child[bit])    curr->child[bit] = new Node();
            curr = curr->child[bit];
        }
    }
    
    int findMaxXor(int n){
        int ans = 0;
        Node *curr = root;
        for(int i=31; i>=0; i--){
            int bit = (n>>i) & 1;
            if(curr->child[1-bit]){
                ans |= (1<<i);
                curr = curr->child[1-bit];
            }
            else    curr = curr->child[bit];
        }
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        for(int i: nums)    insert(i);
    
        int ans = -1;
        for(int i: nums)    ans = max(ans, findMaxXor(i));

        return ans;
    }
};