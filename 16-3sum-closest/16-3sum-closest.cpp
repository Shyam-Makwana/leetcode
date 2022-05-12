class Solution {
public:
    int threeSumClosest(vector<int>& n, int target) {
        sort(n.begin(), n.end());
        int ans=INT_MAX, closest;
        int len = n.size();
        for(int i=0;i<len-2;i++){
            int l=i+1, r = len - 1;
            while(l<r){
                int sum = n[i] + n[l] + n[r];
                if(abs(target-sum)<ans) 
                {
                    ans=abs(target-sum);
                    closest = sum;
                }
                if(sum>target)  r--;
                else l++;
            }
        }
        return closest;
    }
};