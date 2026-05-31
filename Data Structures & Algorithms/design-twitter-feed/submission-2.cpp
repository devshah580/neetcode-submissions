class Twitter {
public:
    struct PairHash {
        size_t operator()(const pair<int,int>& p) const {
            return hash<int>()(p.first) ^
                (hash<int>()(p.second) << 1);
        }
    };

    unordered_map<int, unordered_set<int>> followings;
    int counter = 0;
    unordered_map<int, unordered_set<pair<int, int>, PairHash>> tweets;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].insert({counter, tweetId});
        counter++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int>> heap;
        for(auto elem : followings[userId]) {
            for (auto tweet : tweets[elem]) {
                heap.push(tweet);
            }
        }

        if(!followings[userId].count(userId)) {
            for(auto tweet : tweets[userId]) {
                heap.push(tweet);
            }
        }

        vector<int> result;
        for(int i = 0; i < 10 && heap.size() > 0; i++) {
            result.push_back(get<1>(heap.top()));
            heap.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followings[followerId].count(followeeId)) {
            followings[followerId].erase(followeeId);
        }
    }
};
