/*
310. Minimum Height Trees

https://leetcode.com/problems/minimum-height-trees/
*/
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

/*
  https://www.youtube.com/watch?v=-Tk52eP5n3c
  给一棵树，从那个node出发到别的node的距离最小
  BFS + leave cutting

*/
class Solution
{
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
  {
    vector<int> leaves;
    if (n == 1)
    {
      leaves.push_back(0);
      return leaves;
    }

    vector<unordered_set<int>> graph(n);
    for (const auto &edge : edges)
    {
      graph[edge[1]].insert(edge[0]);
      graph[edge[0]].insert(edge[1]);
    }

    for (int i = 0; i < n; ++i)
    {
      if (graph[i].size() == 1)
        leaves.push_back(i);
    }
    while (n > 2)
    {
      n -= leaves.size();
      vector<int>  newLeaves;
      for (int i : leaves)
      {
        int t = *graph[i].begin();
        graph[t].erase(i);
        if (graph[t].size() == 1)
          newLeaves.push_back(t);
      }
      leaves = newLeaves;
    }
    return leaves;
  }
};