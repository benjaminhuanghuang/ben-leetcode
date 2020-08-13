/*
200. Number of Islands

Level: Medium

https://leetcode.com/problems/number-of-islands
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  /*
    https://zxi.mytechroad.com/blog/searching/leetcode-200-number-of-islands/
    
    Time complexity: O(mn)
    Space complexity: O(mn)


  */
  int numIslands(vector<vector<char>> &grid)
  {
    if (grid.empty())
      return 0;
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    for (int y = 0; y < m; ++y)
      for (int x = 0; x < n; ++x)
      {
        ans += grid[y][x] - '0';
        dfs(grid, x, y, m, n);
      }
    return ans;
  }

private:
  void dfs(vector<vector<char>> &grid, int x, int y, int m, int n)
  {
    if (x < 0 || y < 0 || x >= n || y >= m || grid[y][x] == '0')
      return;
    grid[y][x] = '0';   // visited
    dfs(grid, x + 1, y, m, n);
    dfs(grid, x - 1, y, m, n);
    dfs(grid, x, y + 1, m, n);
    dfs(grid, x, y - 1, m, n);
  }
};