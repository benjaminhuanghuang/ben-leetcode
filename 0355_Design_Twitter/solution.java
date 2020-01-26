package cn.huang.leetcode;

import java.util.*;

/*

    355. Design Twitter

    Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see
    the 10 most recent tweets in the user's news feed. Your design should support the following methods:

    postTweet(userId, tweetId): Compose a new tweet.
    getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must
    be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
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


/*
设计Twitter， 从功能方面分为，关注/取消关注，拿到自己timeline所有的feed， 拿到被关注用户(包括自己)timeline的前N跳feed。
我们需要个map来存用户跟被关注用户的关系。
因为一个用户可以有多个被关注用户所以这里我们需要个userId-> Collection(followerIds)的数据结构；
因为每个用户都有一个timeline列表来存他们发的tweets， 我们需要个userId -> Collection(tweetsId)的数据结构。

follow: 1. 注意是否关注自己 2. 注意检查给定的userId是否存在

unfollow: 注意检查给定的userId是否在用户列表内

postTweet: 注意检查给定用户id是否存在timeline列表

getNewsFeed: 可以先把用户自己的前10条feed，跟用户followees的前10条feeds列表放在一个list里面，然后sort一下，然后返回前N条。 注意comparator的Override， 跟当前用户或者followee的feeds不足10条时候的处理。

 */
public class LC_0355_DesignTwitter {
    class Twitter {
        class Tweet {
            private int time;
            private int tweetId;
            public Tweet(int time, int tweetId) {
                this.time = time;
                this.tweetId = tweetId;
            }
        }

        private HashMap<Integer, HashSet<Integer>> relationship;   //  user: users
        private HashMap<Integer, List<Tweet>> timeline;            //  user: tweets
        private int timestamp;


        /** Initialize your data structure here. */
        public Twitter() {
            relationship = new HashMap<Integer, HashSet<Integer>>();
            timeline = new HashMap<Integer, List<Tweet>>();
        }

        /** Compose a new tweet. */
        public void postTweet(int userId, int tweetId) {
            if (!timeline.containsKey(userId)) {
                timeline.put(userId, new ArrayList<Tweet>());
            }
            timeline.get(userId).add(new Tweet(timestamp++, tweetId));
        }

        /** Retrieve the 10 most recent tweet ids in the user's news feed.
         * Each item in the news feed must be posted by users who the user followed or by the user herself.
         * Tweets must be ordered from most recent to least recent. */
        public List<Integer> getNewsFeed(int userId) {
            HashSet<Integer> followees = relationship.get(userId);
            List<Tweet> ownerTweets = timeline.get(userId);
            List<Tweet> tweetsList = new ArrayList<Tweet>();
            // add owner's own latest 10 tweets to tweetsList
            if (ownerTweets != null) {
                for(int i = ownerTweets.size() - 1; i >= Math.max(0, ownerTweets.size() - 10); i--) { // if owner's tweets < 10, take 0
                    tweetsList.add(ownerTweets.get(i));
                }
            }
            // add each of followees' latest 10 tweets to tweetsList
            if (followees != null) {
                for (Integer followeeId: followees) {
                    List<Tweet> followeeTweets = timeline.get(followeeId);
                    if (followeeTweets == null) continue;
                    for (int i = followeeTweets.size() - 1; i >= Math.max(0, followeeTweets.size() - 10); i--) {
                        tweetsList.add(followeeTweets.get(i));
                    }
                }
            }
            // sort the tweetsList
            Collections.sort(tweetsList, new Comparator<Tweet>() {
                public int compare(Tweet t1, Tweet t2) {
                    return t2.time - t1.time;
                }
            });
            List<Integer> res = new ArrayList<>();
            for (int i = 0; i < Math.min(10, tweetsList.size()); i++) {
                res.add(tweetsList.get(i).tweetId);
            }
            return res;
        }

        /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
        public void follow(int followerId, int followeeId) {
            if (followerId == followeeId)
                return;
            if (!relationship.containsKey(followerId)) {
                relationship.put(followerId, new HashSet<Integer>());
            }
            relationship.get(followerId).add(followeeId);
        }

        /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
        public void unfollow(int followerId, int followeeId) {
            if (!relationship.containsKey(followerId)) return;
            relationship.get(followerId).remove(followeeId);
        }
    }
}
