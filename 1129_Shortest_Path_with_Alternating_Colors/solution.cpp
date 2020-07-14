/*
1129. Shortest Path with Alternating Colors

Level: Medium

https://leetcode.com/problems/shortest-path-with-alternating-colors
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
  HuaHua
  https://zxi.mytechroad.com/blog/graph/leetcode-1129-shortest-path-with-alternating-colors/
*/

class Solution
{
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges, vector<vector<int>> &blue_edges)
  {
    vector<unordered_set<int>> edges_r(n);
    vector<unordered_set<int>> edges_b(n);
    for (const auto &e : red_edges)
      edges_r[e[0]].insert(e[1]);
    for (const auto &e : blue_edges)
      edges_b[e[0]].insert(e[1]);
    unordered_set<int> seen_r;
    unordered_set<int> seen_b;
    vector<int> ans(n, -1);
    queue<pair<int, int>> q; // (node, color)
    q.push({0, 0});          // red
    q.push({0, 1});          // blue
    seen_r.insert(0);
    seen_b.insert(0);
    int steps = 0;
    while (!q.empty())
    {
      int size = q.size();
      while (size--)
      {
        int p = q.front().first;
        int is_red = q.front().second;
        q.pop();
        ans[p] = ans[p] >= 0 ? min(ans[p], steps) : steps;
        const auto &edges = is_red ? edges_r : edges_b;
        auto &seen = is_red ? seen_r : seen_b;
        for (int nxt : edges[p])
        {
          if (seen.count(nxt))
            continue;
          seen.insert(nxt);
          q.push({nxt, 1 - is_red});
        }
      }
      ++steps;
    }
    return ans;
  }
};