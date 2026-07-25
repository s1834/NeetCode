class Twitter {
private:
    void getUserTweets(priority_queue<pair<int, int>>& pq, int& userId) {
        for(auto x : tweets[userId]) pq.push(x);
    }

    void getFollowersTweets(priority_queue<pair<int, int>>& pq, int& userId) {
        for(auto x : followers[userId]) {
            for(auto y : tweets[x]) pq.push(y);
        }
    }

    int time;
    unordered_map<int, set<int>> followers; // unordered_map<followerId, set<followeeId>> followers;
    unordered_map<int, vector<pair<int, int>>> tweets; // unordered_map<userId, vector<pair<time, tweetId>>> tweets;
    
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;

        getUserTweets(pq, userId);
        getFollowersTweets(pq, userId);

        int i = 0;
        vector<int> ans;
        while(!pq.empty() && i < 10) {
            auto temp = pq.top();
            pq.pop();
            ans.push_back(temp.second);
            i++;
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) { 
        if(followerId == followeeId) return;
        followers[followerId].erase(followeeId);
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