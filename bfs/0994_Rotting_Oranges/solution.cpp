/*
994. Rotting Oranges

Level: Medium

https://leetcode.com/problems/rotting-oranges
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
  Solution:  BFS
*/

class Solution
{
public:
  int orangesRotting(vector<vector<int>> &grid)
  {
    const int m = grid.size();
    const int n = grid[0].size();

    queue<pair<int, int>> q;
    int fresh = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1)
          ++fresh;
        else if (grid[i][j] == 2)
          q.emplace(j, i);

    vector<int> dirs = {1, 0, -1, 0, 1};
    int minutes = 0;

    while (!q.empty() && fresh)
    {
      int size = q.size();
      while (size--)
      {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
          // process the fresh orange (1)
          int dx = x + dirs[i];
          int dy = y + dirs[i + 1];
          if (dx < 0 || dx >= n || dy < 0 || dy >= m || grid[dy][dx] != 1)
            continue;
          --fresh;
          grid[dy][dx] = 2;
          q.emplace(dx, dy);
        }
      }
      ++minutes;
    }
    return fresh ? -1 : minutes;
  }
};