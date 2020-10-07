/*
62. Unique Paths

https://leetcode.com/problems/unique-paths/

*/
#include <vector>
#include <unordered_map>

using namespace std;
/*
http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-62-unique-paths/
DP

the recursion pseudocode:
  paths(m, n):
    if(m<0 or n<0) return 0;
    if m ==1 and n == 1
      return 1
    return paths(m-1, n) + paths(m, n -1)

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
        if (y == 1 || x == 1)
          f[y][x] = 1;
        else
          f[y][x] = f[y - 1][x] + f[y][x - 1];
      }

    return f[n][m];
  }
};

/*
  recursion + memoization
  dfs
*/
class Solution
{
public:
  int uniquePaths(int m, int n)
  {
    if (m < 0 || n < 0)
      return 0;
    if (m == 1 && n == 1)
      return 1;
    if (f_[m][n] > 0)
      return f_[m][n];
    int left_paths = uniquePaths(m - 1, n);
    int top_paths = uniquePaths(m, n - 1);
    f_[m][n] = left_paths + top_paths;
    return f_[m][n];
  }

private:
  unordered_map<int, unordered_map<int, int>> f_;
};