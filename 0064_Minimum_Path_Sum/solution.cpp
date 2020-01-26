/*
64. Minimum Path Sum

https://leetcode.com/problems/minimum-path-sum/
*/
#include <vector>

using namespace std;

/*
https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-64-minimum-path-sum/

 Recursion with memoization
 Time complexity: O(mn)

Space complexity: O(mn)
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        
        s_ = vector<vector<int>>(m, vector<int>(n, 0));
        
        return minPathSum(grid, n - 1, m - 1, n, m);
    }    
private:
    long minPathSum(const vector<vector<int>>& grid, 
                   int x, int y, int n, int m) {        
        if (x == 0 && y == 0) return grid[y][x];
        if (x < 0 || y < 0) return INT_MAX;
        if (s_[y][x] > 0) return s_[y][x];
        
        int ans = grid[y][x] + min(minPathSum(grid, x - 1, y, n, m),
                                   minPathSum(grid, x, y - 1, n, m));
        return s_[y][x] = ans;
    }
    
    vector<vector<int>> s_;
};
/*
https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-64-minimum-path-sum/

DP
*/
class Solution
{
public:
  int minPathSum(vector<vector<int>> &grid)
  {
    int m = grid.size();
    if (m == 0)
      return 0;
    int n = grid[0].size();

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
      {
        if (i == 0 && j == 0)
          continue;
        if (i == 0)
          grid[i][j] += grid[i][j - 1];
        else if (j == 0)
          grid[i][j] += grid[i - 1][j];
        else
          grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
      }

    return grid[m - 1][n - 1];
  }
};