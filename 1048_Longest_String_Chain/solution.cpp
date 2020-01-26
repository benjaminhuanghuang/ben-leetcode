/*
1048. Longest String Chain

https://leetcode.com/problems/longest-string-chain/
*/

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;
/*
https://zxi.mytechroad.com/blog/leetcode/leetcode-weekly-contest-137/
Solution: DP

dp[i] := max length of chain of (A[0] ~ A[i-1])

dp[i] = max{dp[j] + 1} if A[j] is prederrsor of A[i], 1 <= j <i

Time complexity: O(n^2*l)
Space complexity: O(n)

*/
class Solution
{
public:
  int longestStrChain(vector<string> &words)
  {
    int n = words.size();
    sort(begin(words), end(words), [](const string &a, const string &b) {
      return a.length() < b.length();
    });
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (valid(words[j], words[i]))
          dp[i] = dp[j] + 1;
    return *max_element(begin(dp), end(dp));
  }

private:
  bool valid(const string &a, const string &b)
  {
    if (a.length() + 1 != b.length())
      return false;
    int count = 0;
    for (int i = 0, j = 0; i < a.length() && j < b.length();)
    {
      if (a[i] == b[j])
      {
        ++i;
        ++j;
      }
      else
      {
        ++count;
        ++j;
      }
    }
    return count <= 1;
  }
};