#include <algorithm>

using namespace std;

/*

*/

class Solution
{
public:
  int minSteps(int n)
  {
    if (n == 1)
      return 0;
    int res = n;
    for (int i = n - 1; i > 1; --i)
    {
      if (n % i == 0)
      {
        res = min(res, minSteps(n / i) + i);
      }
    }
    return res;
  }
};
/*
  Time complexity: O(n^2)
  Space complexity: O(n)
*/
class Solution_DP
{
public:
  int minSteps(int n)
  {
    int dp[n + 1];
    for (int i = 2; i <= n; ++i)
    {
      dp[i] = i;
      for (int j = i - 1; j > 1; --j)
      {
        if (i % j == 0)
        {
          dp[i] = min(dp[i], dp[j] + i / j);
        }
      }
    }
    return dp[n];
  }
};