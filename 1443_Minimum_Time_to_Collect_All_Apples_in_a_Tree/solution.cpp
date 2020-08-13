/*
1443. Minimum Time to Collect All Apples in a Tree

Level: Medium

https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree
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
  https://zxi.mytechroad.com/blog/uncategorized/leetcode-1443-minimum-time-to-collect-all-apples-in-a-tree/
  Solution: 
*/

class Solution
{
public:
  int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
  {
    vector<vector<int>> g(n);
    for (const auto &e : edges)
      g[e[0]].push_back(e[1]);

    function<int(int)> dfs = [&](int cur) {
      int total = 0;
      for (int nxt : g[cur])
      {
        int cost = dfs(nxt);
        if (cost > 0 || hasApple[nxt])
          total += 2 + cost;
      }
      return total;
    };

    return dfs(0);
  }
};

class Solution
{
public:
  int minTime(int n, vector<vector<int>> &edges,
              vector<bool> &hasApple)
  {
    vector<vector<int>> g(n);
    for (const auto &e : edges)
    {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    vector<int> seen(n);
    function<int(int)> dfs = [&](int cur) {
      seen[cur] = 1;
      int total = 0;
      for (int child : g[cur])
      {
        if (seen[child])
          continue;
        int cost = dfs(child);
        if (cost > 0 || hasApple[child])
          total += 2 + cost;
      }
      return total;
    };
    return dfs(0);
  }
};