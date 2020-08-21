/*
1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree

Level: Hard

https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree
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
  Solution: minimum spanning tree (MST)
  https://zxi.mytechroad.com/blog/graph/leetcode-1489-find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
*/

class UnionFind
{
public:
  explicit UnionFind(int n) : p_(n), r_(n) { iota(begin(p_), end(p_), 0); } // e.g. p[i] = i
  int Find(int x) { return p_[x] == x ? x : p_[x] = Find(p_[x]); }
  bool Union(int x, int y)
  {
    int rx = Find(x);
    int ry = Find(y);
    if (rx == ry)
      return false;
    if (r_[rx] == r_[ry])
    {
      p_[rx] = ry;
      ++r_[ry];
    }
    else if (r_[rx] > r_[ry])
    {
      p_[ry] = rx;
    }
    else
    {
      p_[rx] = ry;
    }
    return true;
  }

private:
  vector<int> p_, r_;
};

class Solution
{
public:
  vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
  {
    // Record the original id.
    for (int i = 0; i < edges.size(); ++i)
      edges[i].push_back(i);
    // Sort edges by weight.
    sort(begin(edges), end(edges), [&](const auto &e1, const auto &e2) {
      if (e1[2] != e2[2])
        return e1[2] < e2[2];
      return e1 < e2;
    });
    // Cost of MST, ex: edge to exclude, in: edge to include.
    auto MST = [&](int ex = -1, int in = -1) -> int {
      UnionFind uf(n);
      int cost = 0;
      int count = 0;
      if (in >= 0)
      {
        cost += edges[in][2];
        uf.Union(edges[in][0], edges[in][1]);
        count++;
      }
      for (int i = 0; i < edges.size(); ++i)
      {
        if (i == ex)
          continue;
        if (!uf.Union(edges[i][0], edges[i][1]))
          continue;
        cost += edges[i][2];
        ++count;
      }
      return count == n - 1 ? cost : INT_MAX;
    };
    const int min_cost = MST();
    vector<int> criticals;
    vector<int> pseudos;
    for (int i = 0; i < edges.size(); ++i)
    {
      // Cost increased or can't form a tree.
      if (MST(i) > min_cost)
      {
        criticals.push_back(edges[i][3]);
      }
      else if (MST(-1, i) == min_cost)
      {
        pseudos.push_back(edges[i][3]);
      }
    }
    return {criticals, pseudos};
  }
};