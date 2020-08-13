/*
1254. Number of Closed Islands

Level: Medium

https://leetcode.com/problems/number-of-closed-islands

# 200
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
  https://zxi.mytechroad.com/blog/searching/leetcode-1254-number-of-closed-islands/

  Solution:  DFS/Backtracking

    For each connected component, if it can reach the boundary then it’s not a closed island.

    Time complexity: O(n*m)
    Space complexity: O(n*m)
*/

class Solution
{
public:
  int closedIsland(vector<vector<int>> &grid)
  {
    const int n = grid.size();
    const int m = grid[0].size();

    function<int(int, int)> dfs = [&](int x, int y) {
      if (x < 0 || y < 0 || x >= m || y >= n)
        return 0;
      if (grid[y][x]++)
        return 1;
      return dfs(x + 1, y) & dfs(x - 1, y) & dfs(x, y + 1) & dfs(x, y - 1);
    };

    int ans = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (!grid[i][j])
          ans += dfs(j, i);
    return ans;
  }
};

#define WATER 1
#define GROUND 0
#define VISITED -1

class Solution
{
public:
  void dfs(vector<vector<int>> &grid, int row, int col, bool &isNotSurroundByWater)
  {
    if (grid[row][col] == VISITED)
    {
      return;
    }
    if (grid[row][col] == WATER)
    {
      return;
    }

    if (row == 0 || row == grid.size() - 1 || col == 0 || col == grid[row].size() - 1)
    {
      isNotSurroundByWater = true;
    }

    grid[row][col] = VISITED;

    if (row - 1 >= 0)
      dfs(grid, row - 1, col, isNotSurroundByWater);
    if (col - 1 >= 0)
      dfs(grid, row, col - 1, isNotSurroundByWater);
    if (row + 1 < grid.size())
      dfs(grid, row + 1, col, isNotSurroundByWater);
    if (col + 1 < grid[row].size())
      dfs(grid, row, col + 1, isNotSurroundByWater);
  }

  int closedIsland(vector<vector<int>> &grid)
  {
    int row, col, sum = 0;

    for (row = 0; row < grid.size(); row++)
    {
      for (col = 0; col < grid[row].size(); col++)
      {
        if (grid[row][col] == GROUND)
        {
          bool isNotSurroundByWater = false;
          dfs(grid, row, col, isNotSurroundByWater);
          sum += (int)(!isNotSurroundByWater);
        }
      }
    }

    return sum;
  }
};