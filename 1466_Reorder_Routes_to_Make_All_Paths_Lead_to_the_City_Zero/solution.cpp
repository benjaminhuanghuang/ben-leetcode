/*
1466. Reorder Routes to Make All Paths Lead to the City Zero

Level: Medium

https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero
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
  int minReorder(int n, vector<vector<int>> &connections)
  {
    vector<vector<pair<int, int>>> g(n); // u -> {v, cost}
    for (const auto &e : connections)
    {
      g[e[0]].emplace_back(e[1], 1); // u -> v, needs flip
      g[e[1]].emplace_back(e[0], 0); // v -> u, no cost
    }
    int ans = 0;
    queue<int> q{{0}};
    vector<int> seen(n);
    while (!q.empty())
    {
      int cur = q.front();
      q.pop();
      seen[cur] = 1;
      for (const auto &[nxt, cost] : g[cur])
      {
        if (seen[nxt])
          continue;
        ans += cost;
        q.push(nxt);
      }
    }
    return ans;
  }
};