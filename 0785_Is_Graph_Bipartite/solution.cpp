#include <string>
#include <climits>
#include <vector>
#include <unordered_set>

using namespace std;

/*
https://www.youtube.com/watch?v=Gmp51E8HVVs

https://zxi.mytechroad.com/blog/graph/leetcode-785-is-graph-bipartite/

DFS
  Time complexity: O(V+E)
  Space complexity: O(V)

Similar: # 886
*/
class Solution
{
public:
  bool isBipartite(vector<vector<int>> &graph)
  {
    const int n = graph.size();
    vector<int> colors(n);
    for (int i = 0; i < n; ++i)
      if (!colors[i] && !coloring(graph, colors, 1, i))
        return false;
    return true;
  }

private:
  bool coloring(const vector<vector<int>> &graph, vector<int> &colors, int color, int node)
  {
    if (colors[node])
      return colors[node] == color;
    colors[node] = color;
    for (int nxt : graph[node])
      if (!coloring(graph, colors, -color, nxt))
        return false;
    return true;
  }
};