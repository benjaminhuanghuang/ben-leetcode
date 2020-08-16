/*
823. Binary Trees With Factors

Level: Medium

https://leetcode.com/problems/binary-trees-with-factors
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
  https://zxi.mytechroad.com/blog/tree/leetcode-823-binary-trees-with-factors/
*/

class Solution
{
public:
  int numFactoredBinaryTrees(vector<int> &A)
  {
    constexpr long kMod = 1000000007;
    std::sort(A.begin(), A.end());
    unordered_map<int, long> dp;
    for (int i = 0; i < A.size(); ++i)
    {
      dp[A[i]] = 1;
      for (int j = 0; j < i; ++j)
        if (A[i] % A[j] == 0 && dp.count(A[i] / A[j]))
          dp[A[i]] += (dp[A[j]] * dp[A[i] / A[j]]) % kMod;
    }
    long ans = 0;
    for (const auto &kv : dp)
      ans += kv.second;
    return ans % kMod;
  }
};