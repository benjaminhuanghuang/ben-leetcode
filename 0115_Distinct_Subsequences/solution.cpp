/*
115. Distinct Subsequences

https://leetcode.com/problems/distinct-subsequences/
*/
#include <vector>
#include <string>

using namespace std;
/*
https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-115-distinct-subsequences/

*/
class Solution
{
public:
  int numDistinct(string s, string t)
  {
    int ls = s.length();
    int lt = t.length();
    vector<vector<int>> dp(lt + 1, vector<int>(ls + 1));
    fill(begin(dp[0]), end(dp[0]), 1);
    for (int i = 1; i <= lt; ++i)
      for (int j = 1; j <= ls; ++j)
        dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
    return dp[lt][ls];
  }
};