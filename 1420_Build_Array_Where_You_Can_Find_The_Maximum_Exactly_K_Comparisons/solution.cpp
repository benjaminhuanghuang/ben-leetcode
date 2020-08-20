/*
1420. Build Array Where You Can Find The Maximum Exactly K Comparisons

Level: Hard

https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons
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

  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1420-build-array-where-you-can-find-the-maximum-exactly-k-comparisons/
*/

class Solution
{
private:
  int mem[51][101][51] = {0};

public:
  int numOfArrays(int n, int m, int k)
  {
    const int kMod = 1e9 + 7;
    function<int(int, int, int)> dp = [&](int n, int m, int k) {
      if (k < 1 || k > m || k > n)
        return 0;
      if (n == 1 && k == 1)
        return m;
      if (mem[n][m][k])
        return mem[n][m][k];
      long ans = 0;
      for (int i = 1; i <= m; ++i)
      {
        ans += dp(n - 1, m, k);
        ans += dp(n - 1, i - 1, k - 1);
        ans -= dp(n - 1, i - 1, k);
        ans = (ans + kMod) % kMod;
      }
      return mem[n][m][k] = ans;
    };
    return dp(n, m, k);
  }
};