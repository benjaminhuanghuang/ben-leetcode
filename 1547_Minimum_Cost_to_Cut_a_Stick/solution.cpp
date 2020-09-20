/*
1547. Minimum Cost to Cut a Stick

Level: Hard

https://leetcode.com/problems/minimum-cost-to-cut-a-stick
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
#include <functional>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: DP

  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1547-minimum-cost-to-cut-a-stick/

  dp[i][j] := min cost to finish the i-th cuts to the j-th (in sorted order)
  dp[i][j] = r – l + min(dp[i][k – 1], dp[k + 1][j]) # [l, r] is the current stick range.

  Time complexity: O(n^3)
  Space complexity: O(n^2)
*/

class Solution
{
public:
  int minCost(int n, vector<int> &cuts)
  {
    const int kInf = 1e9;
    sort(begin(cuts), end(cuts));
    const int c = cuts.size();
    vector<vector<int>> cost(c + 1, vector<int>(c + 1, kInf));
    // Min cost to finish i-th cuts to the j-th cut with stick in range [l, r].
    function<int(int, int, int, int)> dp = [&](int i, int j, int l, int r) {
      if (i > j)
        return 0; // Done
      if (i == j)
        return r - l; // One cut, the length of the stick.
      if (cost[i][j] != kInf)
        return cost[i][j];
      int &ans = cost[i][j];
      for (int k = i; k <= j; ++k)
        ans = min(ans, r - l + dp(i, k - 1, l, cuts[k]) + dp(k + 1, j, cuts[k], r));
      return ans;
    };
    return dp(0, c - 1, 0, n);
  }
};