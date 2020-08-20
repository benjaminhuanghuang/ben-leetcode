/*
1478. Allocate Mailboxes

Level: Hard

https://leetcode.com/problems/allocate-mailboxes
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
*/

class Solution {
public:
  int minDistance(vector<int>& houses, int k) {
    constexpr int kInf = 1e9;
    const int n = houses.size();
    sort(begin(houses), end(houses));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, kInf));
    vector<vector<int>> costs(n + 1, vector<int>(n + 1, kInf));
    // min cost to allocate one mailbox for houses[i~j].
    auto cost = [&](int i, int j) {
      int& ans = costs[i][j];
      if (ans != kInf) return ans;
      const int m = i + (j - i) / 2;
      int box = 0;
      if ((j - i + 1) & 1) // odd number of houses.
        box = houses[m];
      else // even number of houses.
        box = (houses[m] + houses[m + 1]) / 2;
      ans = 0;
      for (int h = i; h <= j; ++h)
        ans += abs(houses[h] - box);
      return ans;
    };
    // min cost to allocate k mailboxes for houses[0~i].
    function<int(int, int)> solve = [&](int i, int k) {
      if (k > i) return 0; // more mailboxs than houses.
      if (k == 1) return cost(0, i);
      int& ans = dp[i][k];
      if (ans != kInf) return ans;
      for (int p = 0; p < i; ++p)
        ans = min(ans, solve(p, k - 1) + cost(p + 1, i));
      return ans;
    };
    return solve(n - 1, k);
  }
};