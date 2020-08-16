/*
1348. Tweet Counts Per Frequency

Level: Medium

https://leetcode.com/problems/tweet-counts-per-frequency
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  
  https://www.acwing.com/file_system/file/content/whole/index/content/336412/
  
*/
class TweetCounts
{
public:
  TweetCounts()
  {
    m_.clear();
  }

  void recordTweet(string tweetName, int time)
  {
    m_[tweetName].insert(time);
  }

  vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)
  {
    auto tit = m_.find(tweetName);
    if (tit == m_.end())
      return {};
    const set<int> &s = tit->second;
    int delta = 1;
    if (freq == "minute")
      delta = 60;
    else if (freq == "hour")
      delta = 60 * 60;
    else if (freq == "day")
      delta = 60 * 60 * 24;
    int slots = (endTime - startTime + delta - 1) / delta;
    vector<int> ans(slots);
    for (int i = startTime; i <= endTime; i += delta)
    {
      auto it1 = s.lower_bound(i);
      auto it2 = s.lower_bound(min(i + delta, endTime + 1));
      ans.push_back(distance(it1, it2)); // O(|entries|)
    }
    return ans;
  }

private:
  unordered_map<string, set<int>> m_;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */