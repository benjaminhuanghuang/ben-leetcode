/*
1043. Partition Array for Maximum Sum

Level: Medium

https://leetcode.com/problems/partition-array-for-maximum-sum
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

  https://www.youtube.com/watch?v=3M8q-wB2tmw

  DP

*/

class Solution
{
public:
  int maxSumAfterPartitioning(vector<int> &A, int K)
  {
    int n = A.size();
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
      int m = INT_MIN;
      for (int k = 1; k <= K && i - k >= 0; ++k)
      {
        m = max(m, A[i - k]);
        dp[i] = max(dp[i], dp[i - k] + m * k);
      }
    }
    return dp[n];
  }
};