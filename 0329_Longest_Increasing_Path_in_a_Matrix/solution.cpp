/*
329. Longest Increasing Path in a Matrix [Hard, memoization or Topological Sort]

https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
*/
#include <vector>
#include <queue>

using namespace std;
/*
https://www.cnblogs.com/hankunyan/p/9552061.html

如果把矩阵元素看做点，小的元素到大的元素看做边连起来，这道题等价于在一个有向图中寻找最长路径。

matrix想成一个有向图 directed graph，每个数会指向它上下左右的比他大的数。那么这个最长的path的起点一定是一个只有出度的数。
topological sort，在每个round的中先找出所有入度为0的数， 根据他们的边更新graph，就会有新的入度为0的数出现。每个round代表了path的长度加一。
https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-329-longest-increasing-path-in-a-matrix/

*/
class Solution
{
private:
  vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
  int longestIncreasingPath(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = m == 0 ? 0 : matrix[0].size();

    vector<vector<int>> indegree(m, vector<int>(n, 0));

    // calculate indegree
    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        for (auto dir : dirs)
        {
          int x = i + dir[0], y = j + dir[1];
          if (x >= 0 && x < m && y >= 0 && y < n)
          {
            if (matrix[x][y] < matrix[i][j])   // 周围cell 比 cell[i,j]小，cell[i,j]入度+1
              ++indegree[i][j];
          }
        }
      }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (indegree[i][j] == 0)
          q.push({i, j});
      }
    }

    int len = 0;
    while (!q.empty())
    {
      ++len; // 每层+1
      // 当前层
      int k = q.size();
      for (int cnt = 0; cnt < k; ++cnt)
      {
        auto currCell = q.front();
        q.pop();
        int currX = currCell.first, currY = currCell.second;
        for (auto dir : dirs)
        {
          int nextX = currX + dir[0], nextY = currY + dir[1];
          if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n)
          {
            if (matrix[nextX][nextY] > matrix[currX][currY])
            {
              --indegree[nextX][nextY];
              if (indegree[nextX][nextY] == 0)
              {
                q.push({nextX, nextY});
              }
            }
          }
        }
      }
    }
    return len;
  }
};

/*
https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-329-longest-increasing-path-in-a-matrix/

DFS + Memorization [效率最高]

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
    sort(cells.rbegin(), cells.rend());   //descending

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
