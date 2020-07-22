
/*
  417. Pacific Atlantic Water Flow

  Level: Medium

  https://leetcode.com/problems/pacific-atlantic-water-flow/


  # LC 778 
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <numeric>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  DFS  1 TLE
*/
class Solution
{
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
  {
    if (matrix.empty())
      return {};
    vector<vector<int>> ans;
    for (int i = 0; i < matrix.size(); i++)
    {
      for (int j = 0; j < matrix[0].size(); j++)
      {
        if (dfs(matrix, j, i, matrix[i][j]) == 3)
        {
          ans.push_back({i, j});
        }
      }
    }

    return ans;
  }

private:
  int dfs(vector<vector<int>> &matrix, int x, int y, int h)
  {
    if (x < 0 || y < 0)
      return 1; // pacific
    if (x == matrix[0].size() || y == matrix.size())
      return 2; // atlantic

    // return 3 if can go both pacific and atlantic

    if (matrix[y][x] > h)
      return 0;

    h = matrix[y][x];
    matrix[y][x] = INT_MAX;
    int valid = dfs(matrix, x + 1, y, h) |
                dfs(matrix, x - 1, y, h) |
                dfs(matrix, x, y + 1, h) |
                dfs(matrix, x, y - 1, h);
    matrix[y][x] = h;
    return valid;
  }
};

/*
  DFS 

  https://zxi.mytechroad.com/blog/searching/417-pacific-atlantic-water-flow/
*/
class Solution
{
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
  {
    if (matrix.empty())
      return {};
    const int n = matrix.size();
    const int m = matrix[0].size();

    vector<vector<int>> p(n, vector<int>(m));
    vector<vector<int>> a(n, vector<int>(m));

    for (int x = 0; x < m; ++x)
    {
      dfs(matrix, x, 0, 0, p);     // top
      dfs(matrix, x, n - 1, 0, a); // bottom
    }

    for (int y = 0; y < n; ++y)
    {
      dfs(matrix, 0, y, 0, p);     // left
      dfs(matrix, m - 1, y, 0, a); // right
    }

    vector<vector<int>>ans;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (p[i][j] && a[i][j])
          ans.push_back({i, j});

    return ans;
  }

private:
  void dfs(vector<vector<int>> &b, int x, int y, int h, vector<vector<int>> &v)
  {
    if (x < 0 || y < 0 || x == b[0].size() || y == b.size())
      return;
    if (v[y][x] || b[y][x] < h)
      return;
    v[y][x] = true;
    dfs(b, x + 1, y, b[y][x], v);
    dfs(b, x - 1, y, b[y][x], v);
    dfs(b, x, y + 1, b[y][x], v);
    dfs(b, x, y - 1, b[y][x], v);
  }
};