const int MOD = 1e9 + 7;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& H, vector<int>& V) {
        sort(H.begin(), H.end());
        sort(V.begin(), V.end());
        H.push_back(h);
        V.push_back(w);
        
        long int prev = 0, maxHeight = 0, maxWidth = 0;
        for(int h: H){
            maxHeight = max(maxHeight, (long)h - prev);
            prev = h;
        }
        prev = 0;
        for(int w: V){
            maxWidth = max(maxWidth, (long)w - prev);
            prev = w;
        }
        
        return (maxHeight*maxWidth)%MOD;
    }
};