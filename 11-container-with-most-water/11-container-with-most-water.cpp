class Solution {
public:
    int maxArea(vector<int>& h) {
        int l=0, r=h.size()-1, ans=-1;
        while(l<r){
            ans = max(ans, (r-l)*min(h[l], h[r]));
            if(h[l]<h[r])   l++;
            else r--;
        }
        return ans;
    }
};