/*
1514. Path with Maximum Probability

Level: Medium

https://leetcode.com/problems/path-with-maximum-probability
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
#include <cfloat>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  问题本质是求最短路径，通常是求最短路径之合，本题求最大的路径之product
  Solution:
  https://leetcode.com/problems/path-with-maximum-probability/discuss/731544/C%2B%2B-BFS-explanation-in-comments
*/
class Solution
{
public:
  double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
  {
    //create own graph
    vector<unordered_map<int, double>> graph(n);
    for (int i = 0; i < edges.size(); ++i)
    {
      graph[edges[i][0]][edges[i][1]] = succProb[i];
      graph[edges[i][1]][edges[i][0]] = succProb[i];
    }

    vector<double> ps(n, 0.0); // probability of starto t every node

    ps[start] = 1.0; //important intilization

    queue<int> q;
    q.push(start);
    double res = 0;
    while (!q.empty())
    {
      int curr_node = q.front();
      q.pop();
      for (auto &it : graph[curr_node]) // neighbor and probability
      {
        int next = it.first;
        double pro = it.second;
        if (ps[curr_node] * pro > ps[next]) // 经过 curr_node 到达  next
        {
          q.push(next);
          ps[next] = ps[curr_node] * pro;
        }
      }
    }

    return ps[end];
  }
};

/*
https://zxi.mytechroad.com/blog/graph/leetcode-1514-path-with-maximum-probability/
*/

class Solution_Huahua
{
public:
  double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
  {
    // Build the graph
    vector<vector<pair<int, double>>> graph(n); // u -> {v, -log(w)}
    for (int i = 0; i < edges.size(); ++i)
    {
      graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
      graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
    }

    vector<double> dist(n, FLT_MAX);
    priority_queue<pair<double, int>> q;
    q.emplace(-0.0, start);
    vector<int> seen(n);
    while (!q.empty())
    {
      const double d = -q.top().first;
      const int u = q.top().second;
      q.pop();
      seen[u] = 1;
      if (u == end)
        return exp(-d);
      for (const auto &[v, w] : g[u])
      {
        if (seen[v] || d + w > dist[v])
          continue;
        q.emplace(-(dist[v] = d + w), v);
      }
    }
    return 0;
  }
};