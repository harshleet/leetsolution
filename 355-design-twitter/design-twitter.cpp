class Twitter {
public:
    map<int,set<int>>fol;
    map<int,vector<pair<int,int>>>tweets;
    int tn=0;
    Twitter() {
        tn=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tn,tweetId});
        tn++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(auto it:fol[userId]){
            for(int i=0;i<tweets[it].size();i++){
                pq.push(tweets[it][i]);
            }
        }
        for(int i=0;i<tweets[userId].size();i++){
                pq.push(tweets[userId][i]);
        }
        for(int i=0;i<10&& !pq.empty();i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        fol[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fol[followerId].erase(followeeId);
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