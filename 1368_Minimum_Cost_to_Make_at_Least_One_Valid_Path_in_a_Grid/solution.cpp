/*
1368. Minimum Cost to Make at Least One Valid Path in a Grid

Level: Hard

https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid
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
  Solution: 
  https://zxi.mytechroad.com/blog/searching/leetcode-1368-minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
*/

class Solution {
public:
  int minCost(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    deque<pair<int, int>> q{{0, 0}};
    vector<char> seen(m * n);
    vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty()) {
      auto [p, cost] = q.front(); q.pop_front();
      int x = p % n, y = p / n;
      if (x == n - 1 && y == m - 1) return cost;
      if (seen[p]++) continue;
      for (int i = 0; i < 4; ++i) {
        int tx = x + dirs[i][0], ty = y + dirs[i][1];
        int tp = ty * n + tx;
        if (tx < 0 || ty < 0 || tx >= n || ty >= m || seen[tp]) continue;
        if (grid[y][x] == i + 1)
          q.emplace_front(tp, cost);
        else
          q.emplace_back(tp, cost + 1);
      }
    }    
    return -1;
  }
};