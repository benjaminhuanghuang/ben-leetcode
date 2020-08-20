/*
778. Swim in Rising Water

Level: Hard

https://leetcode.com/problems/swim-in-rising-water
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
  https://zxi.mytechroad.com/blog/heap/leetcode-778-swim-in-rising-water/
*/

class Solution
{
public:
  int swimInWater(vector<vector<int>> &grid)
  {
    const int n = grid.size();
    auto hasPath = [&grid, n](int t) {
      if (grid[0][0] > t)
        return false;
      queue<int> q;
      vector<int> seen(n * n);
      vector<int> dirs{1, 0, -1, 0, 1};
      q.push(0);

      while (!q.empty())
      {
        const int x = q.front() % n;
        const int y = q.front() / n;
        q.pop();
        if (x == n - 1 && y == n - 1)
          return true;
        for (int i = 0; i < 4; ++i)
        {
          const int tx = x + dirs[i];
          const int ty = y + dirs[i + 1];
          if (tx < 0 || ty < 0 || tx >= n || ty >= n || grid[ty][tx] > t)
            continue;
          const int key = ty * n + tx;
          if (seen[key])
            continue;
          seen[key] = 1;
          q.push(key);
        }
      }
      return false;
    };
    int l = 0;
    int r = n * n;
    while (l < r)
    {
      int m = l + (r - l) / 2;
      if (hasPath(m))
      {
        r = m;
      }
      else
      {
        l = m + 1;
      }
    }
    return l;
  }
};