/*
62. Unique Paths

https://leetcode.com/problems/unique-paths/

*/
#include <vector>

using namespace std;
/*
http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-62-unique-paths/
DP
*/
class Solution
{
public:
  int uniquePaths(int m, int n)
  {
    auto f = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
    f[1][1] = 1;

    for (int y = 1; y <= n; ++y)
      for (int x = 1; x <= m; ++x)
      {
        if (x == 1 && y == 1)
        {
          continue;
        }
        else
        {
          f[y][x] = f[y - 1][x] + f[y][x - 1];
        }
      }

    return f[n][m];
  }
};