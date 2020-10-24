/*
981. Time Based Key-Value Store

Level: Medium

https://leetcode.com/problems/time-based-key-value-store
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution:  binary search, Upper bound
*/

class TimeMap
{
public:
  /** Initialize your data structure here. */
  TimeMap()
  {
  }

  void set(string key, string value, int timestamp)
  {
    s_[key].emplace(timestamp, std::move(value));
  }

  string get(string key, int timestamp)
  {
    auto m = s_.find(key);
    if (m == s_.end())
      return "";
    auto it = m->second.upper_bound(timestamp);
    if (it == begin(m->second))
      return "";
    return prev(it)->second;
  }

private:
  unordered_map<string, map<int, string>> s_; // key: {timestamp, value}
};
class TimeMap
{
private:
  map<string, vector<pair<int, string>>> mmap;

public:
  TimeMap()
  {
  }

  void set(string key, string value, int timestamp)
  {
    mmap[key].emplace_back(timestamp, value);
  }

  string get(string key, int timestamp)
  {
    if (mmap.find(key) == mmap.end())
      return "";
    int n = mmap[key].size();
    if (mmap[key][0].first > timestamp)
      return "";

    // 二分查找
    int l = 0, r = n - 1;
    while (l <= r)
    {
      int m = (l + r) / 2;
      if (mmap[key][m].first == timestamp)
        return mmap[key][m].second;
      else if (mmap[key][m].first < timestamp)
        l = m + 1;
      else
        r = m - 1;
    } // use r
    // if (mmap[key][r].first <= timestamp)
    //     return mmap[key][r].second;
    return mmap[key][r].second;
  }
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */