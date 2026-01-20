class Twitter {
public:
    map<int,priority_queue<pair<int,int>>>post;
    map<int,map<int,int>>Follow;
    int start = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
       start++;
       post[userId].push({start,tweetId});
       Follow[userId][userId] = 1;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<pair<int,int>>temp;
        for(auto it : Follow[userId]){
            auto q = post[it.first];
            int count = 10;
            while(q.size() && count){
                temp.push(q.top());
                q.pop();
                count--;
            } 
        }
        int count = 10;
        while(temp.size() && count){
            ans.push_back(temp.top().second);
            temp.pop();
            count--;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        Follow[followerId][followeeId] = 1;
        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        if(!Follow[followerId].count(followeeId)){
            return;
        }
        Follow[followerId].erase(followeeId);
        return;
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