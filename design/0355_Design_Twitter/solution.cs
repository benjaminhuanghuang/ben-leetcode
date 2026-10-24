/*
355. Design Twitter

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user 
and is able to see the 10 most recent tweets in the user's news feed. Your design should support 
the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in 
the news feed must be posted by users who the user followed or by the user herself. Tweets must 
be ordered from most recent to least recent.
follow(followerId, followeeId): Follower follows a followee.
unfollow(followerId, followeeId): Follower unfollows a followee.
Example:

Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
*/

//http://bookshadow.com/weblog/2016/06/11/leetcode-design-twitter/
// http://blog.csdn.net/mebiuw/article/details/51781415
//# https://www.hrwhisper.me/leetcode-design-twitter/

/*

设计Twitter， 从功能方面分为，关注/取消关注，拿到自己timeline所有的feed， 拿到被关注用户(包括自己)timeline的
前N跳feed。 我们需要个map来存用户跟被关注用户的关系。 因为一个用户可以有多个被关注用户所以这里我们需要个
userId-> Collection(followerIds)的数据结构； 因为每个用户都有一个timeline列表来存他们发的tweets， 
我们需要个userId -> Collection(tweetsId)的数据结构。
follow: 1. 注意是否关注自己 2. 注意检查给定的userId是否存在
unfollow: 注意检查给定的userId是否在用户列表内
postTweet: 注意检查给定用户id是否存在timeline列表
getNewsFeed: 可以先把用户自己的前10条feed，跟用户followees的前10条feeds列表放在一个list里面，然后sort一下，
然后返回前N条。 注意comparator的Override， 跟当前用户或者followee的feeds不足10条时候的处理。
 */
using System;
using System.Collections.Generic;

public class Twitter
{
    class Tweet
    {
        public int time;
        public int tweetId;
        public Tweet(int time, int tweetId)
        {
            this.time = time;
            this.tweetId = tweetId;
        }
    }
    private Dictionary<int, HashSet<int>> relationship; //userid : followers
    private Dictionary<int, List<Tweet>> timeline;      //userid : tweets
    private int timestamp;
    /** Initialize your data structure here. */
    public Twitter()
    {
        relationship = new Dictionary<int, HashSet<int>>();
        timeline = new Dictionary<int, List<Tweet>>();
    }

    /** Compose a new tweet. */
    public void PostTweet(int userId, int tweetId)
    {
        if (!timeline.ContainsKey(userId))
        {
            timeline.Add(userId, new List<Tweet>());
        }
        timeline[userId].Add(new Tweet(timestamp++, tweetId));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed 
    must be posted by users who the user followed or by the user herself. Tweets must be ordered 
    from most recent to least recent. */
    public IList<int> GetNewsFeed(int userId)
    {
        HashSet<int> followees = relationship[userId];
        List<Tweet> ownerTweets = timeline[userId];
        List<Tweet> tweetsList = new List<Tweet>();
        // add owner's own least 10 tweets to tweetsList
        if (ownerTweets != null)
        {
            for (int i = ownerTweets.Count - 1; i >= Math.Max(0, ownerTweets.Count - 10); i--)
            { // if owner's tweets < 10, take 0
                tweetsList.Add(ownerTweets[i]);
            }
        }
        // add each of followees' latest 10 tweets to tweetsList
        if (followees != null)
        {
            foreach (int followeeId in followees)
            {
                List<Tweet> followeeTweets = timeline[followeeId];
                if (followeeTweets == null) continue;
                for (int i = followeeTweets.Count - 1; i >= Math.Max(0, followeeTweets.Count - 10); i--)
                {
                    tweetsList.Add(followeeTweets[i]);
                }
            }
        }
        // sort the tweetsList
        tweetsList.Sort((x, y) => { return x.time - y.time; });

        List<int> res = new List<int>();
        foreach (Tweet tweet in tweetsList)
        {
            res.Add(tweet.tweetId);
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void Follow(int followerId, int followeeId)
    {
        if (followerId == followeeId) return;
        if (!relationship.ContainsKey(followerId)) {
            relationship[followerId] =  new HashSet<int>();
        }
        relationship[followerId].Add(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void Unfollow(int followerId, int followeeId)
    {
        if (!relationship.ContainsKey(followerId)) 
            return;
        relationship[followerId].Remove(followeeId);
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.PostTweet(userId,tweetId);
 * IList<int> param_2 = obj.GetNewsFeed(userId);
 * obj.Follow(followerId,followeeId);
 * obj.Unfollow(followerId,followeeId);
 */
