/*
354. Russian Doll Envelopes

Level: Hard

https://leetcode.com/problems/russian-doll-envelopes
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
  https://www.cnblogs.com/grandyang/p/5568818.html

  http://www.noteanddata.com/leetcode-354-Russian-Doll-Envelopes-google-interview-problem-java-solution-note.html
*/

class Solution_TLE
{
public:
  int maxEnvelopes(vector<vector<int>> &envelopes)
  {
    int res = 0, n = envelopes.size();
    vector<int> dp(n, 1);
    sort(envelopes.begin(), envelopes.end());
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < i; ++j)
      {
        if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
        {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      res = max(res, dp[i]);
    }
    return res;
  }
};
/*
  https://www.cnblogs.com/grandyang/p/5568818.html
  用二分查找法来优化速度
*/
class Solution
{
public:
  int maxEnvelopes(vector<vector<int>> &envelopes)
  {
    vector<int> dp;
    sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b) {
      if (a[0] == b[0])
        return a[1] > b[1];
      return a[0] < b[0];
    });

    for (int i = 0; i < envelopes.size(); ++i)
    {
      int left = 0, right = dp.size(), t = envelopes[i][1];
      while (left < right)
      {
        int mid = left + (right - left) / 2;
        if (dp[mid] < t)
          left = mid + 1;
        else
          right = mid;
      }
      if (right >= dp.size())
        dp.push_back(t);
      else
        dp[right] = t;
    }
    return dp.size();
  }
};