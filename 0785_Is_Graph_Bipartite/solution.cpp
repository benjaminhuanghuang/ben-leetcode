/*
785. Is Graph Bipartite?

https://leetcode.com/problems/is-graph-bipartite/


验证给定的图是否是二分图，所谓二分图，就是可以将图中的所有顶点分成两个不相交的集合，使得同一个集合的顶点不相连。
为了验证是否有这样的"两个不相交的集合"存在，我们采用"染色法"，大体上的思路是要将相连的两个顶点染成不同的颜色，
一旦在染的过程中发现有两连的两个顶点已经被染成相同的颜色，说明不是二分图。
这里我们使用两种颜色，分别用1和-1来表示，初始时每个顶点用0表示未染色，然后遍历每一个顶点，如果该顶点未被访问过，
则调用递归函数，如果返回false，那么说明不是二分图，则直接返回false。如果循环退出后没有返回false，则返回true。
在递归函数中，如果当前顶点已经染色，如果该顶点的颜色和将要染的颜色相同，则返回true，否则返回false。
如果没被染色，则将当前顶点染色，然后再遍历与该顶点相连的所有的顶点，调用递归函数，如果返回false了，
则当前递归函数的返回false，循环结束返回true：
*/

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