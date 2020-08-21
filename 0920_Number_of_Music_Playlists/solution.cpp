/*
920. Number of Music Playlists

Level: Hard

https://leetcode.com/problems/number-of-music-playlists
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
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-920-number-of-music-playlists/
*/

class Solution
{
public:
  int numMusicPlaylists(int N, int L, int K)
  {
    constexpr long kMod = 1e9 + 7;
    vector<vector<long>> dp(L + 1, vector<long>(N + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= L; ++i)
      for (int j = 1; j <= min(i, N); ++j)
        dp[i][j] = (dp[i - 1][j - 1] * (N - (j - 1)) +
                    dp[i - 1][j] * max(j - K, 0)) %
                   kMod;
    return dp[L][N];
  }
};