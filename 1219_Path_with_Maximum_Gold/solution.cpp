/*
1219. Path with Maximum Gold

Level: Medium

https://leetcode.com/problems/path-with-maximum-gold
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
  Solution:  DFS
  https://zxi.mytechroad.com/blog/searching/leetcode-1219-path-with-maximum-gold/
  
*/

class Solution
{
public:
  int getMaximumGold(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;

    function<int(int, int)> dfs = [&](int x, int y) {
      if (x < 0 || x >= m || y < 0 || y >= n || grid[y][x] == 0)
        return 0;
      int c = 0;
      swap(c, grid[y][x]);
      int r = c + max({dfs(x - 1, y), dfs(x + 1, y), dfs(x, y - 1), dfs(x, y + 1)});
      swap(c, grid[y][x]);
      return r;
    };

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        ans = max(ans, dfs(j, i));
    return ans;
  }
};