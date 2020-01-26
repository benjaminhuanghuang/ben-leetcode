/*
63. Unique Paths II

https://leetcode.com/problems/unique-paths-ii/
*/
#include <vector>

using namespace std;
/*
https://www.cnblogs.com/grandyang/p/4353680.html

DP
*/
class Solution
{
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1)
      return 0;
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));

    dp[0][1] = 1;  // 即dp[1][1] = 1，由于其是由 dp[0][1] + dp[1][0] 更新而来，所以二者中任意一个初始化为1即可
    for (int i = 1; i <= m; ++i)
    {
      for (int j = 1; j <= n; ++j)
      {
        if (obstacleGrid[i - 1][j - 1] != 0)
          continue;
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m][n];
  }
};

class Solution2
{
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1)
      return 0;
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<long> dp(n, 0);
    dp[0] = 1;
    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (obstacleGrid[i][j] == 1)
          dp[j] = 0;
        else if (j > 0)
          dp[j] += dp[j - 1];
      }
    }
    return dp[n - 1];
  }
};