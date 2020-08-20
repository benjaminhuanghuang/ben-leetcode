/*
805. Split Array With Same Average

Level: Hard

https://leetcode.com/problems/split-array-with-same-average
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
  Solution: DFS

  https://zxi.mytechroad.com/blog/searching/leetcode-805-split-array-with-same-average/
*/

class Solution
{
public:
  bool splitArraySameAverage(vector<int> &A)
  {
    std::sort(A.begin(), A.end());
    sum = std::accumulate(A.begin(), A.end(), 0);
    n = A.size();
    return dfs(A, 1, 0, 0);
  }

private:
  int sum;
  int n;
  bool dfs(const vector<int> &A, int c, int s, int cur)
  {
    if (c > A.size() / 2)
      return false;
    for (int i = s; i < A.size(); ++i)
    {
      cur += A[i];
      if (cur * (n - c) == (sum - cur) * c)
        return true;
      if (cur * (n - c) > (sum - cur) * c)
        break;
      if (dfs(A, c + 1, i + 1, cur))
        return true;
      cur -= A[i];
    }
    return false;
  }
};

/*
  DP
*/

class Solution
{
public:
  bool splitArraySameAverage(vector<int> &A)
  {
    int n = A.size();
    if (n <= 1)
      return false;
    int sum = accumulate(A.begin(), A.end(), 0);
    vector<int> dp(sum + 1, 0);
    dp[A[0]] = 2;
    for (int i = 1; i < n; i++)
    {
      for (int s = sum - A[i]; s >= 0; s--)
      {
        if (dp[s])
        {
          dp[s + A[i]] |= (dp[s] << 1);
        }
      }
      dp[A[i]] = 2;
    }
    for (int len = 1; len < n; len++)
    {
      if ((sum * len) % n == 0 && (1 << len) & dp[(sum * len) / n])
      {
        return true;
      }
    }
    return false;
  }
};