/*
221. Maximal Square

Level: Medium

https://leetcode.com/problems/maximal-square


- 85. Maximal Rectangle
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
  Solution: 

  http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-221-maximal-square/
*/

class Solution
{
public:
  /*
      main loop m*n*min(m,n)
      check: O(m*n)
      Total(m^2n*2*min(m,n)) = n^5
    */
  int maximalSquare_bruteforce(vector<vector<char>> &matrix)
  {
  }

  /*
    Time complexity: O(n^3)
    */
  int maximalSquare(vector<vector<char>> &matrix)
  {
    if (matrix.empty())
      return 0;
    int m = matrix.size();
    int n = matrix[0].size();

    // sums[i][j] = sum(matrix[0][0] ~ matrix[i-1][j-1])
    vector<vector<int>> sums(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        sums[i][j] = matrix[i - 1][j - 1] - '0' + sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];

    int ans = 0;
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        for (int k = min(m - i + 1, n - j + 1); k > 0; --k)
        {
          int sum = sums[i + k - 1][j + k - 1] - sums[i + k - 1][j - 1] - sums[i - 1][j + k - 1] + sums[i - 1][j - 1];
          // full of 1
          if (sum == k * k)
          {
            ans = max(ans, sum);
            break;
          }
        }

    return ans;
  }
  /*
    Time complexity: O(n^2)
  */
  int maximalSquare_v2(vector<vector<char>> &matrix)
  {
    if (matrix.empty())
      return 0;
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> sizes(m, vector<int>(n, 0));

    int ans = 0;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
      {
        sizes[i][j] = matrix[i][j] - '0';
        if (!sizes[i][j])
          continue;

        if (i == 0 || j == 0)
        {
          // do nothing
        }
        else if (i == 0)
          sizes[i][j] = sizes[i][j - 1] + 1;
        else if (j == 0)
          sizes[i][j] = sizes[i - 1][j] + 1;
        else
          sizes[i][j] = min(min(sizes[i - 1][j - 1],
                                sizes[i - 1][j]),
                            sizes[i][j - 1]) +
                        1;

        ans = max(ans, sizes[i][j] * sizes[i][j]);
      }
    return ans;
  }

  int maximalSquare(vector<vector<char>> &A)
  {
    int r = A.size(), c = r > 0 ? A[0].size() : 0;
    vector<vector<int>> dp(r + 1, vector<int>(c + 1, 0));
    int mx_side = 0;
    for (int i = 1; i <= r; i++)
    {
      for (int j = 1; j <= c; j++)
      {
        if (A[i - 1][j - 1] == '1')
        {
          dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
          mx_side = max(mx_side, dp[i][j]);
        }
      }
    }
    return mx_side * mx_side;
  }
};