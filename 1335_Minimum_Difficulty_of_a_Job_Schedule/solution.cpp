/*
1335. Minimum Difficulty of a Job Schedule

Level: Hard

https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule
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
  Solution: DP
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1335-minimum-difficulty-of-a-job-schedule/
*/

class Solution
{
public:
  int minDifficulty(vector<int> &jobs, int d)
  {
    const int n = jobs.size();
    if (d > n)
      return -1;
    vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX / 2));

    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = i - 1, md = 0; j >= 0; --j)
      {
        md = max(md, jobs[j]);
        for (int k = 1; k <= min(i, d); ++k)
          dp[i][k] = min(dp[i][k], dp[j][k - 1] + md);
      }

    return dp[n][d];
  }
};