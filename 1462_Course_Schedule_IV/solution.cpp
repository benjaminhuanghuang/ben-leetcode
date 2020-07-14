/*
1462. Course Schedule IV

Level: Medium

https://leetcode.com/problems/course-schedule-iv
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
    Floyd-Warshall Algorithm (All pairs shortest paths)

    Time complexity: O(n^3 + q)
    Space complexity: O(n^2)
*/

class Solution
{
public:
  vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
  {
    vector<vector<int>> g(n, vector<int>(n));
    for (const auto &p : prerequisites)
      g[p[0]][p[1]] = 1;

    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          g[i][j] |= g[i][k] & g[k][j];

    vector<bool> ans;
    for (const auto &q : queries)
      ans.push_back(g[q[0]][q[1]]);
    return ans;
  }
};
/*
  Solution: 
    BFS
   https://www.youtube.com/watch?v=SfkkQSvHWxM 
*/
class Solution_BFS
{
private:
  void buildPrerequistieTable(vector<int> &out_edges,
                              vector<vector<int>> &reverse_graphs,
                              unordered_map<int, unordered_set<int>> &table)
  {
    queue<int> q;
    for (int i = 0; i < out_edges.size(); ++i)
    {
      if (out_edges[i] == 0)
      {
        q.push(i);
      }
    }

    while (!q.empty())
    {
      int high_level_course = q.front();
      q.pop();
      for (auto pre : reverse_graphs[high_level_course])
      {
        if (--out_edges[pre] == 0)
        {
          q.push(pre);
        }
        table[pre].insert(high_level_course);
        table[pre].insert(table[high_level_course].begin(), table[high_level_course].end());
      }
    }
  }

public:
  vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
  {
    // build graph
    vector<vector<int>> reverse_graph(n, vector<int>());
    vector<int> out_edges(n, 0);

    for (auto course : prerequisites)
    {
      // [i, j] means course[1] depends course[1]
      reverse_graph[course[1]].push_back(course[0]);
      out_edges[course[0]]++;
    }

    // build map
    unordered_map<int, unordered_set<int>> huge_table;

    buildPrerequistieTable(out_edges, reverse_graph, huge_table);

    vector<bool> res;

    for (auto q : queries)
    {
      res.push_back(huge_table[q[0]].count(q[1]));
    }

    return res;
  }

  bool isPrerequisite(int source, int target, vector<vector<int>> graph)
  {
    queue<int> q;
    unordered_set<int> visited;
    q.push(source);
    visited.insert(source);

    while (!q.empty())
    {
      int src = q.front();
      for (auto next : graph[src])
      {
        if (visited.count(next))
        {
          continue;
        }
        if (next == target)
        {
          return true;
        }
        visited.insert(next);
        q.push(next);
      }
    }
    return false;
  }
};
