/*
695. Max Area of Island

https://leetcode.com/problems/max-area-of-island/
*/

#include <vector>

using namespace std;

class Solution
{
public:
  int maxAreaOfIsland(vector<vector<int>> &grid)
  {
    int rows = grid.size();
    int cols = grid[0].size();

    int ans = 0;
    for (int row = 0; row < rows; ++row)
      for (int col = 0; col < cols; ++col)
        ans = max(ans, area(grid, row, col, rows, cols));
    return ans;
  }

private:
  int area(vector<vector<int>> &grid, int row, int col, int rows, int cols)
  {
    if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 0)
      return 0;

    grid[row][col] = 0;

    return area(grid, row - 1, col, rows, cols) 
            + area(grid, row + 1, col, rows, cols) 
            + area(grid, row, col - 1, rows, cols) 
            + area(grid, row, col + 1, rows, cols) + 1;
  }
};
