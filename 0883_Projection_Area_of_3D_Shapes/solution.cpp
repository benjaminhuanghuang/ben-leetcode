/*
883. Projection Area of 3D Shapes

Level: Easy

https://leetcode.com/problems/projection-area-of-3d-shapes
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
  Solution: Sum of max heights for each cols / rows + # of non-zero-height bars.

  Time complexity: O(mn)
  Space complexity: O(1)
*/

class Solution
{
public:
  int projectionArea(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
      int h = 0;
      for (int j = 0; j < m; ++j)
      {
        h = max(h, grid[i][j]);
        if (grid[i][j] != 0)
          ++ans;   // bottom
      }
      ans += h;
    }
    for (int j = 0; j < m; ++j)
    {
      int h = 0;
      for (int i = 0; i < n; ++i)
        h = max(h, grid[i][j]);
      ans += h;
    }
    return ans;
  }
};