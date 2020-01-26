/*
329. Longest Increasing Path in a Matrix [Hard, memoization]

https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
*/
#include <vector>

using namespace std;

/*
https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-329-longest-increasing-path-in-a-matrix/

DFS + Memorization

Time complexity: O(mn)
Space complexity: O(mn)
*/
class Solution
{
public:
  int longestIncreasingPath(vector<vector<int>> &matrix)
  {
    if (matrix.empty())
      return 0;
    rows = matrix.size();
    cols = matrix[0].size();
    mem = vector<vector<int>>(rows, vector<int>(cols, -1));
    int longestPath = 0;

    for (int row = 0; row < rows; ++row)
      for (int col = 0; col < cols; ++col)
        longestPath = max(longestPath, dfs(matrix, row, col));
    return longestPath;
  }

private:
  int dfs(const vector<vector<int>> &matrix, int row, int col)
  {
    if (mem[row][col] != -1)
      return mem[row][col];
    static int dirs[] = {0, -1, 0, 1, 0};
    mem[row][col] = 1;
    for (int i = 0; i < 4; ++i)
    {
      int nRow = row + dirs[i];
      int nCol = col + dirs[i + 1];
      if (nRow < 0 || nCol < 0 || nRow >= rows || nCol >= cols || matrix[nRow][nCol] <= matrix[row][col])
        continue;
      mem[row][col] = max(mem[row][col], 1 + dfs(matrix, nRow, nCol));
    }
    return mem[row][col];
  }

  int rows;
  int cols;
  // mem[i][j]: max length start from (j, i)
  vector<vector<int>> mem;
};

/*
https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-329-longest-increasing-path-in-a-matrix/
DP
Time complexity: O(mn*log(mn))
Space complexity: O(mn)
*/
class Solution
{
public:
  int longestIncreasingPath(vector<vector<int>> &matrix)
  {
    if (matrix.empty())
      return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 1));
    int ans = 0;

    vector<pair<int, pair<int, int>>> cells;
    for (int y = 0; y < m; ++y)
      for (int x = 0; x < n; ++x)
        cells.push_back({matrix[y][x], {x, y}});
    sort(cells.rbegin(), cells.rend());

    vector<int> dirs{0, 1, 0, -1, 0};
    for (const auto &cell : cells)
    {
      int x = cell.second.first;
      int y = cell.second.second;
      for (int i = 0; i < 4; ++i)
      {
        int tx = x + dirs[i];
        int ty = y + dirs[i + 1];
        if (tx < 0 || tx >= n || ty < 0 || ty >= m)
          continue;
        if (matrix[ty][tx] <= matrix[y][x])
          continue;
        dp[y][x] = max(dp[y][x], 1 + dp[ty][tx]);
      }
      ans = max(ans, dp[y][x]);
    }
    return ans;
  }
};
