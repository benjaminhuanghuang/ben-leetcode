/*
354. Russian Doll Envelopes

Level: Hard

https://leetcode.com/problems/russian-doll-envelopes

# 300
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
    // 从小到大排序，首先根据宽度从小到大排，如果宽度相同，那么高度小的再前面，这是STL里面sort的默认排法
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

  思路是先建立一个空的 dp 数组，然后开始遍历原数组，对于每一个遍历到的数字，用二分查找法在 dp 数组找第一个不小于它的数字，
  如果这个数字不存在，那么直接在 dp 数组后面加上遍历到的数字，
  如果存在，则将这个数字更新为当前遍历到的数字，最后返回 dp 数组的长度即可
*/
class Solution
{
public:
  int maxEnvelopes(vector<vector<int>> &envelopes)
  {
    vector<int> dp;

    // Sort  宽度从小到大排，宽度相等时，让高度大的在前面
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