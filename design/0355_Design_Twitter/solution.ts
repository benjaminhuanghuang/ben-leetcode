/*
355. Design Twitter

https://leetcode.com/problems/design-twitter/
*/

class Twitter {
  // Global time variable
  private time: number;
  // Map of userId to an array of [time, tweetId]
  private userTweets: Map<number, Array<[number, number]>>;
  // Map of userId to a set of userIds that the user follows
  private userFollowers: Map<number, Set<number>>;
  private static readonly kMaxTweets = 10;

  constructor() {
    this.time = 0;
    this.userTweets = new Map();
    this.userFollowers = new Map();
  }

  postTweet(userId: number, tweetId: number): void {
    if (!this.userTweets.has(userId)) {
      this.userTweets.set(userId, []);
    }

    const tweets = this.userTweets.get(userId)!;
    if (tweets.length === Twitter.kMaxTweets) {
      tweets.shift();
    }

    tweets.push([++this.time, tweetId]);
  }

  getNewsFeed(userId: number): number[] {
    let feed: [number, number][] = [];

    if (this.userTweets.has(userId)) {
      feed = [...this.userTweets.get(userId)!];
    }

    const followers = this.userFollowers.get(userId) || new Set();
    for (const uid of followers) {
      if (this.userTweets.has(uid)) {
        feed.push(...this.userTweets.get(uid)!);
      }
    }

    feed.sort((a, b) => b[0] - a[0]); // Sort by time descending
    return feed.slice(0, Twitter.kMaxTweets).map(([_, tweetId]) => tweetId);
  }

  follow(followerId: number, followeeId: number): void {
    if (followerId === followeeId) return;

    if (!this.userFollowers.has(followerId)) {
      this.userFollowers.set(followerId, new Set());
    }

    this.userFollowers.get(followerId)!.add(followeeId);
  }

  unfollow(followerId: number, followeeId: number): void {
    if (followerId === followeeId) return;

    if (this.userFollowers.has(followerId)) {
      this.userFollowers.get(followerId)!.delete(followeeId);
    }
  }
}
