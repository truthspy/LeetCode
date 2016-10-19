struct Tweet {
    int userId;
    int timestamp;
    int tweetId;
};
struct cmp {
    bool operator()(list<Tweet>::iterator &a, list<Tweet>::iterator &b) {
        return (*a).timestamp < (*b).timestamp;
    }
};
class Twitter {
private:
    unordered_map<int, unordered_set<int>> friends;
    unordered_map<int, list<Tweet>> tweets;
    int timestamp;
public:
    
    /** Initialize your data structure here. */
    Twitter() {
        timestamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(tweets.find(userId) == tweets.end()) {
            list<Tweet> cur;
            tweets[userId] = cur;
        }
        Tweet newTweet;
        newTweet.userId = userId;
        newTweet.tweetId = tweetId;
        newTweet.timestamp = timestamp;
        tweets[userId].push_front(newTweet);
        timestamp ++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<list<Tweet>::iterator, vector<list<Tweet>::iterator>, cmp> pq;
        friends[userId].insert(userId);
        for(auto id : friends[userId]) {
            if(tweets.find(id) != tweets.end())
                pq.push(tweets[id].begin());
        }
        while(res.size() < 10 && !pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            res.push_back((*cur).tweetId);
            int id = (*cur).userId;
            cur ++;
            if(cur != tweets[id].end()) {
                pq.push(cur);
            }
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(friends.find(followerId) == friends.end()) {
            unordered_set<int> followee;
            friends[followerId] = followee;
        }
        friends[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(friends.find(followerId) != friends.end())
            friends[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
