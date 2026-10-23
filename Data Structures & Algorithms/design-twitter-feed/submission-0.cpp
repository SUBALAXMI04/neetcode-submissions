class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>> Tweet;
    unordered_map<int,unordered_set<int>> Follow;
    int timestamp = 0;
    Twitter(){ }
    
    void postTweet(int userId,int tweetId){
        Tweet[userId].push_back({timestamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId){
        priority_queue<pair<int,int>> pq;
        auto addTweet = [&](int id){
            auto it = Tweet.find(id);
            if(it == Tweet.end()) return;
            for(auto &p : it->second) pq.push(p);
        };
        addTweet(userId);
        for(auto id : Follow[userId]) addTweet(id);
        vector<int> ans;
        while(ans.size() < 10 && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId,int followeeId){
        if(followerId != followeeId) Follow[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId,int followeeId){
        Follow[followerId].erase(followeeId);
    }
};
