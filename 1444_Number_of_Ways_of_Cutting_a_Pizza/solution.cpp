/*
1444. Number of Ways of Cutting a Pizza

Level: Hard

https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza
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
  Solution: 

  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1444-number-of-ways-of-cutting-a-pizza/
*/
class Solution
{
public:
  int ways(vector<string> &pizza, int K)
  {
    constexpr int kMod = 1e9 + 7;
    const int M = pizza.size();
    const int N = pizza[0].size();

    vector<vector<int>> A(M + 1, vector<int>(N + 1));
    for (int y = 0; y < M; ++y)
      for (int x = 0; x < N; ++x)
        A[y + 1][x + 1] = A[y + 1][x] + A[y][x + 1] + (pizza[y][x] == 'A') - A[y][x];

    auto hasApples = [&](int x1, int y1, int x2, int y2) {
      return (A[y2 + 1][x2 + 1] - A[y2 + 1][x1] - A[y1][x2 + 1] + A[y1][x1]) > 0;
    };

    vector<vector<vector<int>>> cache(M, vector<vector<int>>(N, vector<int>(K, -1)));

    // dp(m, n, k) := # of ways to cut pizza[m:M][n:N] with k cuts.
    function<int(int, int, int)> dp = [&](int m, int n, int k) -> int {
      if (k == 0)
        return hasApples(n, m, N - 1, M - 1);
      int &ans = cache[m][n][k];
      if (ans != -1)
        return ans;
      ans = 0;
      for (int y = m; y < M - 1; ++y) // Cut horizontally.
        ans = (ans + hasApples(n, m, N - 1, y) * dp(y + 1, n, k - 1)) % kMod;
      for (int x = n; x < N - 1; ++x) // Cut vertically.
        ans = (ans + hasApples(n, m, x, M - 1) * dp(m, x + 1, k - 1)) % kMod;
      return ans;
    };
    return dp(0, 0, K - 1);
  }
};