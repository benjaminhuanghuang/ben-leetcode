/*
1320. Minimum Distance to Type a Word Using Two Fingers

Level: Hard

https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers
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
  Solution:  DP
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1320-minimum-distance-to-type-a-word-using-two-fingers/
*/

class Solution {
public:
    int minimumDistance(string word) {
        constexpr int kRest = 26;
    const int n = word.length();
       
    // dp[i][j] : min cost to type word[0:i]
    // one finger is at word[i - 1], another finger is at j.
    vector<vector<int>> dp(n + 1, vector<int>(27, INT_MAX / 2));
    
    dp[0][kRest] = 0;
    
    auto cost = [](int c1, int c2) {
      if (c1 == kRest) return 0;
      return abs(c1 / 6 - c2 / 6) + abs(c1 % 6 - c2 % 6);
    };
    
    for (int i = 0; i < n; ++i) {
      int p = i == 0 ? kRest : word[i - 1] - 'A';
      int c = word[i] - 'A';
      for (int j = 0; j <= 26; ++j) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + cost(p, c));  // same finger
        dp[i + 1][p] = min(dp[i + 1][p], dp[i][j] + cost(j, c)); // other finger
      }
    }
    
    return *min_element(begin(dp[n]), end(dp[n])); 
    }
};