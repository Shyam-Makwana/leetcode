class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*max_element(piles.begin(), piles.end());
        while(l<=r){
            int mid = (r+l)/2, total_hrs = 0;
            for(int i:piles)    total_hrs += (ceil(i*1.0/mid));
            if(total_hrs<=h)    r = mid-1;
            else l = mid+1;
        }
        return l;
    }
};