/*
1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

Level: Medium

https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance
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
  Hua Hua
  https://zxi.mytechroad.com/blog/graph/leetcode-1334-find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
*/

class Solution_FloydWarshall
{
public:
  int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
  {
    // 初始化成 INT_MAX / 2是因为在后面的计算中会相加，如果定义为INT_MAX会溢出
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 2));
    // dp[i][j] 记录 i j之间的weight
    for (const auto &e : edges)
      dp[e[0]][e[1]] = dp[e[1]][e[0]] = e[2];

    // 找到任意两点之间的最小路径
    for (int k = 0; k < n; ++k)
      for (int u = 0; u < n; ++u)
        for (int v = 0; v < n; ++v)
          dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v]);

    int ans = -1;
    int min_nb = INT_MAX;
    for (int u = 0; u < n; ++u)
    {
      int nb = 0;
      for (int v = 0; v < n; ++v)
        if (v != u && dp[u][v] <= distanceThreshold)
          ++nb;
      if (nb <= min_nb)
      {
        min_nb = nb;
        ans = u;
      }
    }

    return ans;
  }
};