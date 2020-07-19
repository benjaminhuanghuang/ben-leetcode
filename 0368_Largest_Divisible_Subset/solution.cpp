/*
368. Largest Divisible Subset

Level: Medium

https://leetcode.com/problems/largest-divisible-subset
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  https://www.cnblogs.com/grandyang/p/5625209.html
*/

class Solution
{
public:
  vector<int> largestDivisibleSubset(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    vector<int> res;
    vector<pair<int, int>> dp(nums.size());
    int mx = 0, mx_idx = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
      for (int j = i; j >= 0; --j)
      {
        if (nums[i] % nums[j] == 0 && dp[i].first < dp[j].first + 1)
        {
          dp[i].first = dp[j].first + 1;
          dp[i].second = j;
          if (mx < dp[i].first)
          {
            mx = dp[i].first;
            mx_idx = i;
          }
        }
      }
    }
    for (int i = 0; i < mx; ++i)
    {
      res.push_back(nums[mx_idx]);
      mx_idx = dp[mx_idx].second;
    }
    return res;
  }
};