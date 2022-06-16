struct Node{
    Node *child[2] = {NULL};
};

class Solution {
private:
    Node *root = new Node();
    
public:
    
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

    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), -1); 
        vector<pair<int, pair<int,int>>> offlineQueries; 
        sort(arr.begin(), arr.end()); 
        
        int index = 0;
        for(auto it: queries)   offlineQueries.push_back({it[1],{it[0], index++}}); 
        sort(offlineQueries.begin(), offlineQueries.end());
        
        int i = 0; 
        for(auto it : offlineQueries) {
            while(i < arr.size() && arr[i] <= it.first) insert(arr[i++]); 
            if(i) ans[it.second.second] = findMaxXor(it.second.first); 
        }
        return ans; 
    }
};