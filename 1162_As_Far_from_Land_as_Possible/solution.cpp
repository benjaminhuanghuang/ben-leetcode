/*
1162. As Far from Land as Possible

Level: Medium

https://leetcode.com/problems/as-far-from-land-as-possible
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
   BFS
    Put all land cells into a queue as source nodes and BFS for water cells, the last expanded one will be the farthest.

    Time compleixty: O(n^2)
    Space complexity: O(n^2)
*/

class Solution
{
public:
  int maxDistance(vector<vector<int>> &grid)
  {
    const int n = grid.size();
    const int m = grid[0].size();
    int ans = -1;
    queue<pair<int,int>> q; 
    // Put all land cells into a queue 
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (grid[i][j] == 1)
          q.push({i ,j});  // land

    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int steps = 0;
    while (q.size())
    {
      int size = q.size();
      while (size--)
      {
        auto p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        if (grid[y][x] == 2)
          ans = max(ans, steps);
        for (auto d : dirs)
        {
          int tx = x + d.first;
          int ty = y + d.second;
          if (tx < 0 || tx >= m || ty < 0 || ty >= n || grid[ty][tx] != 0)
            continue;
          grid[ty][tx] = 2;
          q.push({ty, tx});
        }
      }
      ++steps;
    }
    return ans;
  }
};