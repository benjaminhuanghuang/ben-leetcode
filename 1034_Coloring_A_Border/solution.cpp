/*
1034. Coloring A Border

https://leetcode.com/problems/coloring-a-border/
*/

#include <vector>
#include <string>
#include <unordered_set>

#include <algorithm>
using namespace std;
/*
  DFS
  https://xingxingpark.com/Leetcode-1034-Coloring-A-Border/
*/
class Solution
{
public:
  vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r0, int c0, int color)
  {
    vector<vector<int>> b(grid.size(), vector<int>(grid[0].size()));
    dfs(grid, r0, c0, grid[r0][c0], b);
    for (int i = 0; i < b.size(); ++i)
      for (int j = 0; j < b[0].size(); ++j)
        if (b[i][j] > 0)
          grid[i][j] = color;
    return grid;
  }

private:
  bool dfs(const vector<vector<int>> &grid, int r, int c, int color, vector<vector<int>> &b)
  {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
      return true;
    if (grid[r][c] != color)
      return true;
    if (b[r][c])
      return false;
    b[r][c] = -1;
    bool valid = dfs(grid, r + 1, c, color, b) |
                 dfs(grid, r - 1, c, color, b) |
                 dfs(grid, r, c + 1, color, b) |
                 dfs(grid, r, c - 1, color, b);
    if (valid)
      b[r][c] = 1;
    return false;
  }
};