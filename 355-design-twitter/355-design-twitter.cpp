class Twitter {
public:
    //userid, following
    unordered_map<int, unordered_set<int>> fo;
    //userid, vector of recent time and tweetid
    unordered_map<int, vector<pair<int, int>>> t;
    //for recent tweets
    int time;
    
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        t[userId].push_back({time++, tweetId});
        
        //so, if he follows himself, we don't have to traverse through 2 for loop.
        //One for getting his tweets and another by his following.
        fo[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        //time and tweetId
        priority_queue<pair<int, int>> maxHeap;
        
        //This is for getting the tweets by themself
        //We added his own id to following, i.e. he follows himself
        /*for(auto userTweets=t[userId].begin(); userTweets!=t[userId].end(); userTweets++){
            maxHeap.push(*userTweets);
        }*/
        
        //This is for getting the tweets by their following
        for(auto foTweets=fo[userId].begin(); foTweets!=fo[userId].end(); foTweets++){
            int userId = *foTweets;
            for(auto userTweets=t[userId].begin(); userTweets!=t[userId].end(); userTweets++){
                maxHeap.push(*userTweets);
            }
        }
        
        //Adding all the recent tweets based on time using Max Heap
        vector<int> recentTweets;
        while(!maxHeap.empty()){
            recentTweets.push_back(maxHeap.top().second);
            if(size(recentTweets)==10)   break;
            maxHeap.pop();
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