/*
1391. Check if There is a Valid Path in a Grid

Level: Medium

https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: BFS
  Need to check both sides (x, y) -> (tx, ty) and (tx, ty) -> (x, y) to make sure a path exist.
  https://zxi.mytechroad.com/blog/searching/leetcode-1391-check-if-there-is-a-valid-path-in-a-grid/

*/

class Solution
{
public:
  bool hasValidPath(vector<vector<int>> &grid)
  {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<int> dirs{0, -1, 0, 1, 0}; // [up, left, down, right]
    vector<set<int>> rules{
        {1, 3}, {0, 2}, {1, 2}, {2, 3}, {0, 1}, {0, 3}};
    queue<int> q{{0}};
    vector<int> seen(m * n);
    seen[0] = 1;
    while (!q.empty())
    {
      int cx = q.front() % n;
      int cy = q.front() / n;
      q.pop();
      if (cx == n - 1 && cy == m - 1)
        return true;
      for (int d : rules[grid[cy][cx] - 1])
      {
        int x = cx + dirs[d];
        int y = cy + dirs[d + 1];
        int key = y * n + x;
        if (x < 0 || x >= n || y < 0 || y >= m || seen[key] || !rules[grid[y][x] - 1].count((d + 2) % 4))
          continue;
        seen[key] = 1;
        q.push(key);
      }
    }
    return false;
  }
};