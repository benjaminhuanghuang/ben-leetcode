/*
1137. N-th Tribonacci Number

Level: Easy

https://leetcode.com/problems/n-th-tribonacci-number
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
*/

class Solution
{
public:
  int tribonacci(int n)
  {
    if (n == 0)
    {
      return 0;
    }
    if (n < 3)
    {
      return 1;
    }
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
      dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
  }
};