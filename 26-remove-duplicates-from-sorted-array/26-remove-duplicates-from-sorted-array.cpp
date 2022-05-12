class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), k=0;
        map<int, int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])==mp.end())    {
                nums[k++]=nums[i];
                mp[nums[i]]=i;
            }
        }
        return k;
    }
};