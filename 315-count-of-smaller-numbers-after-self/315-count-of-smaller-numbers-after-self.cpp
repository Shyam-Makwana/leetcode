    class Solution {
public:
    void merge(vector<int> &count, vector<pair<int, int> > &v, int left, int mid, int right) {
        vector<pair<int, int> > tmp(right-left+1);
        int i = left;
        int j = mid+1;
        int k = 0;
        int cnt = 0;
        
        while (i <= mid && j <= right) {
            //cout<<v[i].first<<' '<<v[j].first<<endl;
            // mind that we're sorting in descending order
            if (v[i].first <= v[j].first) { 
                count[v[i].second] += cnt;
                tmp[k++] = v[i++];
            }
            else {
                // only line responsible to update count, related to problem constraint, 
                // remaining part is just regular mergeSort 
                // count[v[i].second] += right - j + 1;
                cnt++;
                tmp[k++] = v[j++];
            }
        }
        while (i <= mid) {
            count[v[i].second] += cnt;
            tmp[k++] = v[i++];
        }
        while (j <= right) {
            tmp[k++] = v[j++];
        }
        for (int i = left; i <= right; i++)
            v[i] = tmp[i-left];
        //for(auto i: v)  cout<<i.first<<' ';
        //cout<<endl;
    }        

    void mergeSort(vector<int> &count, vector<pair<int, int> > &v, int left, int right) {
        if (left >= right) 
            return;

        int mid = left + (right-left)/2;
        mergeSort(count, v, left, mid);
        mergeSort(count, v, mid+1, right);
        merge(count, v, left, mid, right);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int N = nums.size();

        vector<pair<int, int> > v(N);
        for (int i = 0; i < N; i++)   
            v[i] = make_pair(nums[i], i);

        vector<int> count(N, 0);
        // sorting in descending order
        mergeSort(count, v, 0, N-1);

        return count;
    }
};