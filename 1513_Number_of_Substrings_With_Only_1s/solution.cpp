/*
1513. Number of Substrings With Only 1s

Level: Medium

https://leetcode.com/problems/number-of-substrings-with-only-1s
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

  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1513-number-of-substrings-with-only-1s/
*/

class Solution
{
public:
  int numSub(string s)
  {
    constexpr int kMod = 1e9 + 7;
    long ans = 0;
    vector<int> dp(s.length() + 1);
    for (int i = 1; i <= s.length(); ++i)
    {
      dp[i] = s[i - 1] == '1' ? dp[i - 1] + 1 : 0;
      ans += dp[i];
    }
    return ans % kMod;
  }
};