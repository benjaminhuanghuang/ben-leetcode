/*
279. Perfect Squares

Level: Medium

https://leetcode.com/problems/perfect-squares
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 

  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-279-perfect-squares/

  dp[i] 表示正整数i能少能由多个完全平方数组成，最差情况i可以由i个i组成
  dp[i] := ans
  dp[0] = 0
  dp[i] = min{dp[i – j * j] + 1} 1 <= j * j <= i

  dp[5] = min{
  dp[5 – 2 * 2] + 1 = dp[1] + 1 = (dp[1 – 1 * 1] + 1) + 1 = dp[0] + 1 + 1 = 2,
  dp[5 – 1 * 1] + 1 = dp[3] + 1 = (dp[3 – 1 * 1] + 1) + 1 = dp[1] + 2 = dp[1 – 1*1] + 1 + 2 = dp[0] + 3 = 3
  };

  dp[5] = 2

  Time complexity: O(n * sqrt(n))
  Space complexity: O(n)
*/

class Solution
{
public:
  int numSquares(int n)
  {
    vector<int> dp(n + 1, INT_MAX >> 1);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j * j <= i; ++j) // j为i之前的完全平方数
        dp[i] = min(dp[i], dp[i - j * j] + 1); // +1 是因为i被拆成 i-j*j 和 j*j，而j*j是完全平方数
    return dp[n];
  }
};