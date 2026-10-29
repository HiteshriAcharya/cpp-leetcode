#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Twitter {
private:
    int time;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int,int>>> tweets; // first is time and second is 

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time += 1;
        tweets[userId].push_back(make_pair(time, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int,int>> pq;

        for(auto tweet : tweets[userId]){
            pq.push(tweet);
        }

        for(auto follower : following[userId]){
            for(auto tweet : tweets[follower]){
                pq.push(tweet);
            }
        }

        vector<int> feed;

        while(!pq.empty() && feed.size() < 10){
            feed.push_back(pq.top().second);
            pq.pop();
        }
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};