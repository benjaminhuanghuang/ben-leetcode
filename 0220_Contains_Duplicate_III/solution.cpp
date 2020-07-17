/*
220. Contains Duplicate III

Level: Medium

https://leetcode.com/problems/contains-duplicate-iii
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <set>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: Sliding Window + Multiset (OrderedSet)

  Maintaining a sliding window of sorted numbers of k + 1. 
  After the i-th number was inserted into the sliding window, check whether its left and right neighbors satisfy abs(nums[i] – neighbor) <= t

  Time complexity: O(nlogk)
  Space complexity: O(k)
*/

class Solution
{
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
  {
    multiset<long> s;
    for (int i = 0; i < nums.size(); ++i)
    {
      if (i > k)
        s.erase(s.find(nums[i - k - 1]));

      auto it = s.insert(nums[i]);
      if (it != begin(s) && *it - *prev(it) <= t)
        return true;
      if (next(it) != end(s) && *next(it) - *it <= t)
        return true;
    }
    return false;
  }
};

/*
https://www.youtube.com/watch?v=yc4hCFzNNQc
*/
/*
  Time complexity O(N*K)
  Space complexity O(1)
*/
class Solution_BruteForce
{
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
  {
    if (nums.size() == 0 || k <= 0 || t < 0)
      return false;
    for (int i = 0; i < nums.size(); ++i)
    {
      for (int j = i + 1; j - i <= k && j < nums.size(); ++j)
      {
        // overflow!!!
        if (abs((long)nums[i] - nums[j]) <= t)
          return true;
      }
    }
    return false;
  }
};
/*
    Time complexity: O(nlogk)
    Space complexity: O(k)
*/
class Solution_Set
{
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
  {
    if (nums.size() == 0 || k <= 0 || t < 0)
      return false;

    multiset<int> s;

    for (int i = 0; i < nums.size(); ++i)
    {
      auto ceil = s.lower_bound(nums[i]); // first element that is not less than val.
      if (ceil != s.end() && (long)*ceil - nums[i] <= t)
        return true;

      if (ceil != s.begin())
      {
        auto floor = prev(ceil); //  smaller than val.
        if (floor != s.end() && nums[i] - (long)*floor <= t)
          return true;
      }
      s.insert(nums[i]);

      if (i >= k)
      {
        s.erase(nums[i - k]);
      }
    }
    return false;
  }
};

class Solution_SlidingWindow
{
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
  {
    if (nums.size() == 0 || k <= 0 || t < 0)
      return false;

    multiset<int> s;

    for (int i = 0; i < nums.size(); ++i)
    {
      auto ceil = s.lower_bound(nums[i]); // first element that is not less than val.
      if (ceil != s.end() && (long)*ceil - nums[i] <= t)
        return true;

      if (ceil != s.begin())
      {
        auto floor = prev(ceil); //  smaller than val.
        if (floor != s.end() && nums[i] - (long)*floor <= t)
          return true;
      }
      s.insert(nums[i]);

      if (i >= k)
      {
        s.erase(nums[i - k]);
      }
    }
    return false;
  }
};