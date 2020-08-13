/*
1254. Number of Closed Islands

Level: Medium

https://leetcode.com/problems/number-of-closed-islands
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