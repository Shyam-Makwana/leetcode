class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> mp;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        int l=0, r=size(mp[key])-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(mp[key][mid].second<=timestamp){
                ans = mp[key][mid].first;
                l = mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */