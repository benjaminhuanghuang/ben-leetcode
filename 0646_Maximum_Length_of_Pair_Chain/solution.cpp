/*
646. Maximum Length of Pair Chain

Level: Medium

https://leetcode.com/problems/maximum-length-of-pair-chain
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
*/

class Solution
{
public:
  int findLongestChain(vector<vector<int>> &pairs)
  {
    int m = pairs.size();
    int dp[m];
    fill_n(dp, m, 1);
    sort(pairs.begin(), pairs.end());

    int maxLen = 1;

    for (int i = 1; i < m; i++)
    {
      for (int j = i - 1; j >= 0; j--)
      {
        if (pairs[i][0] > pairs[j][1])
        {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
  }
};