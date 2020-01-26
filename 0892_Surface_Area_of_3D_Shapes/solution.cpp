/*
892. Surface Area of 3D Shapes

https://leetcode.com/problems/surface-area-of-3d-shapes/
*/

#include <vector>

using namespace std;
/*
https://zxi.mytechroad.com/blog/geometry/leetcode-892-surface-area-of-3d-shapes/
Ans = total faces – hidden faces.

each pile with height h has the surface area of 2 (top/bottom) + 4*h (sides)

ans = ans +2+4*h

if a cube has a neighbour, reduce the total surface area by 1

For each pile, we check 4 neighbours, the number of total hidden faces of this pile is sum(min(h, neighbour’s h)).

ans = ans – min (h,neighbours.h)
Time complexity: O(mn)
Space complexity: O(1)
Related to 463. Island Perimeter
*/
class Solution
{
public:
  int surfaceArea(vector<vector<int>> &grid)
  {
    static const vector<int> dirs{0, -1, 0, 1, 0};
    int m = grid.size();
    int n = grid[0].size();
    int surface = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
      {
        int h = grid[i][j];
        if (h == 0)
          continue;
        surface += 2 + 4 * h;
        // 4 neighbours
        for (int k = 0; k < 4; k++)
        {
          // get neighbour x, y
          int tx = j + dirs[k];
          int ty = i + dirs[k + 1];
          if (tx < 0 || tx >= n || ty < 0 || ty >= m)
            continue;
          int th = grid[ty][tx];  // height of neighbour
          surface -= (th <= 0 ? 0 : min(h, th));
        }
      }
    return surface;
  }
};
/*
Since the neighbor relationship is symmetric, 
we can only consider the top and left neighbors and double the hidden faces.
(0,0)(0,1)
(1,0)
(0,0)与(0,1)之间会有 2*hidden faces
(0,0)与(1,0)之间会有 2*hidden faces
*/
class Solution
{
public:
  int surfaceArea(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size();
    int surface = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
      {
        int h = grid[i][j];
        if (h == 0)
          continue;
        surface += 2 + 4 * h;
        if (i)
          surface -= 2 * min(h, grid[i - 1][j]);
        if (j)
          surface -= 2 * min(h, grid[i][j - 1]);
      }
    return surface;
  }
};


class Solution_my
{
public:
  int surfaceArea(vector<vector<int>> &grid)
  {
    int surface = 0;
    for (int row = 0; row < grid.size(); row++)
    {
      for (int col = 0; col < grid[0].size(); col++)
      {
        surface++;
        //
        if (row == 0)
        {
          surface += grid[row][col];
        }
        if (row > 0)
        {
          surface += grid[row][col] - grid[row - 1][col];
        }
        if (row < grid.size() - 1)
        {
          surface += grid[row][col] - grid[row - 1][col];
        }
      }
    }
  }
};
