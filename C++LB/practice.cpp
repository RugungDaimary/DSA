#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    pair<int, int> val;
    Node *next;
    Node(int t, int id)
    {
        this->val = {t, id};
        this->next = NULL;
    }
};
class Twitter
{
    unordered_map<int, unordered_set<int>> m;
    unordered_map<int, Node *> tweets;
    int t = 0;

public:
    Twitter()
    {
        m.clear();
        tweets.clear();
    }

    void postTweet(int userId, int tweetId)
    {
        auto itr = tweets.find(userId);
        if (itr == tweets.end())
        {
            Node *newNode = new Node({t++, tweetId});
            tweets[userId] = newNode;
        }
        else
        {
            Node *newNode = new Node({t++, tweetId});
            newNode->next = itr->second;
            tweets[userId] = newNode;
        }
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> ans;
        priority_queue<pair<int, Node *>> pq;
        auto itr = tweets.find(userId);
        if (itr != tweets.end())
        {
            pq.push({itr->second->val.first, itr->second});
        }
        for (auto followee : m[userId])
        {
            auto itr = tweets.find(followee);
            if (itr != tweets.end())
            {
                pq.push({itr->second->val.first, itr->second});
            }
        }
        while (!pq.empty() && ans.size() < 10)
        {
            auto tp = pq.top();
            pq.pop();
            ans.push_back(tp.second->val.second);
            if (tp.second->next)
                pq.push({tp.second->next->val.first, tp.second->next});
        }
        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        m[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        auto itr = m[followerId].find(followeeId);
        if (itr != m[followerId].end())
        {
            m[followerId].erase(itr);
        }
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
int main(){


    
    
    return 0;
}
