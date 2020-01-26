/*
547. Friend Circles

https://leetcode.com/problems/friend-circles/
*/

#include <vector>
#include <unordered_set>

using namespace std;

/*
http://zxi.mytechroad.com/blog/graph/leetcode-547-friend-circles/

*/
class Solution_DFS
{
public:
  int findCircleNum(vector<vector<int>> &M)
  {
    if (M.empty())
      return 0;
    int n = M.size();
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
      if (!M[i][i])
        continue;
      ++ans;
      dfs(M, i, n);
    }
    return ans;
  }

private:
  void dfs(vector<vector<int>> &M, int curr, int n)
  {
    // Visit all friends (neighbors)
    for (int i = 0; i < n; ++i)
    {
      if (!M[curr][i])
        continue;
      M[curr][i] = M[i][curr] = 0;
      dfs(M, i, n);
    }
  }
};

#include "common/DSU.h"

class Solution_UnionFind
{
public:
  int findCircleNum(vector<vector<int>> &M)
  {
    int n = M.size();
    DSU s(n);
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) // 矩阵是对称的
        if (M[i][j] == 1)             // i and j are friends
          s.Union(i, j);

    unordered_set<int> circles;
    for (int i = 0; i < n; ++i)
      circles.insert(s.Find(i));

    return circles.size();    // return the cluster count
  }
};

class Solution_UnionFind2
{
public:
  int findCircleNum(vector<vector<int>> &M)
  {
    int n = M.size();
    DSU s(n);
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) // 矩阵是对称的
        if (M[i][j] == 1)             // i and j are friends
          s.Union(i, j);
    return s.Size();
  }
};