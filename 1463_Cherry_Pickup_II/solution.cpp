/*
1463. Cherry Pickup II

Level: Hard

https://leetcode.com/problems/cherry-pickup-ii
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
  Solution:  DP
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1463-cherry-pickup-ii/
*/

class Solution
{
public:
  int cherryPickup(vector<vector<int>> &grid)
  {
    const int r = grid.size();
    const int c = grid[0].size();
    vector<vector<vector<int>>> cache(r, vector<vector<int>>(c, vector<int>(c, -1)));
    function<int(int, int, int)> dp = [&](int y, int x1, int x2) {
      if (x1 < 0 || x1 >= c || x2 < 0 || x2 >= c || y < 0 || y >= r)
        return 0;
      int &ans = cache[y][x1][x2];
      if (ans != -1)
        return ans;
      const int cur = grid[y][x1] + (x1 != x2) * grid[y][x2];
      for (int d1 = -1; d1 <= 1; ++d1)
        for (int d2 = -1; d2 <= 1; ++d2)
          ans = max(ans, cur + dp(y + 1, x1 + d1, x2 + d2));
      return ans;
    };
    return dp(0, 0, c - 1);
  }
};