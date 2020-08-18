/*
935. Knight Dialer

Level: Medium

https://leetcode.com/problems/knight-dialer

# 688
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
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-935-knight-dialer/
*/

class Solution
{
public:
  int knightDialer(int N)
  {
    constexpr int kMod = 1e9 + 7;
    int dirs[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    vector<vector<int>> dp(4, vector<int>(3, 1));
    dp[3][0] = dp[3][2] = 0;
    for (int k = 1; k < N; ++k)
    {
      vector<vector<int>> tmp(4, vector<int>(3));
      for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 3; ++j)
        {
          if (i == 3 && j != 1)
            continue;
          for (int d = 0; d < 8; ++d)
          {
            int tx = j + dirs[d][0];
            int ty = i + dirs[d][1];
            if (tx < 0 || ty < 0 || tx >= 3 || ty >= 4)
              continue;
            tmp[i][j] = (tmp[i][j] + dp[ty][tx]) % kMod;
          }
        }
      dp.swap(tmp);
    }
    int ans = 0;
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 3; ++j)
        ans = (ans + dp[i][j]) % kMod;
    return ans;
  }
};