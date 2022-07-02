class Twitter {
public:
    //userid, following
    unordered_map<int, set<int>> fo;
    //userid, vector of recent time and tweetid
    unordered_map<int, vector<pair<int, int>>> t;
    //for recent tweets
    int time;
    
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        t[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        //time and tweetId
        priority_queue<pair<int, int>> maxHeap;
        
        for(auto userTweets=t[userId].begin(); userTweets!=t[userId].end(); userTweets++){
            maxHeap.push(*userTweets);
        }
        
        for(auto foTweets=fo[userId].begin(); foTweets!=fo[userId].end(); foTweets++){
            int userId = *foTweets;
            for(auto userTweets=t[userId].begin(); userTweets!=t[userId].end(); userTweets++){
                maxHeap.push(*userTweets);
            }
        }
        vector<int> recentTweets;
        while(!maxHeap.empty()){
            recentTweets.push_back(maxHeap.top().second);
            maxHeap.pop();
            if(size(recentTweets)==10)   break;
        }
        return recentTweets;
    }
    
    void follow(int followerId, int followeeId) {
        fo[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fo[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */