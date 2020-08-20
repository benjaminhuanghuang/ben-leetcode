/*
1340. Jump Game V

Level: Hard

https://leetcode.com/problems/jump-game-v
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Recursion w/ Memoization

  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1344-jump-game-v/
*/
class Solution
{
public:
  int maxJumps(vector<int> &a, int d)
  {
    int n = a.size();
    vector<int> m(n);
    function<int(int)> dp = [&](int i) {
      if (m[i])
        return m[i];
      int ans = 1;
      for (int j = i + 1; j <= min(n - 1, i + d) && a[i] > a[j]; ++j)
        ans = max(ans, dp(j) + 1);
      for (int j = i - 1; j >= max(0, i - d) && a[i] > a[j]; --j)
        ans = max(ans, dp(j) + 1);
      return m[i] = ans;
    };

    int ans = 0;
    for (int i = 0; i < n; ++i)
      ans = max(ans, dp(i));
    return ans;
  }
};

/*
  Solution:  DP
*/

class Solution
{
public:
  int maxJumps(vector<int> &arr, int d)
  {
    const int n = a.size();
    vector<pair<int, int>> m(n); // <height, index>
    for (int i = 0; i < n; ++i)
      m[i] = {a[i], i};
    // Solve from the lowest bar.
    sort(begin(m), end(m));

    vector<int> dp(n, 1);
    for (auto [v, i] : m)
    {
      for (int j = i + 1; j <= min(n - 1, i + d) && a[i] > a[j]; ++j)
        dp[i] = max(dp[i], dp[j] + 1);
      for (int j = i - 1; j >= max(0, i - d) && a[i] > a[j]; --j)
        dp[i] = max(dp[i], dp[j] + 1);
    }

    return *max_element(begin(dp), end(dp));
  }
};