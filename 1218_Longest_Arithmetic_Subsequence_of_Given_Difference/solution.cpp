/*
1218. Longest Arithmetic Subsequence of Given Difference

Level: Medium

https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference
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
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1218-longest-arithmetic-subsequence-of-given-difference/
  Solution: DP
*/

class Solution
{
public:
  int longestSubsequence(vector<int> &arr, int difference)
  {
    unordered_map<int, int> dp;
    int ans = 0;
    for (int x : arr)
      ans = max(ans, dp[x] = dp[x - difference] + 1);
    return ans;
  }
};