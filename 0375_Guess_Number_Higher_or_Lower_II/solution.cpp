/*
375. Guess Number Higher or Lower II

Level: Medium

https://leetcode.com/problems/guess-number-higher-or-lower-ii
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
#include <functional>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-375-guess-number-higher-or-lower-ii/
*/

class Solution
{
public:
  int getMoneyAmount(int n)
  {
    constexpr int kInf = 1e9;
    vector<vector<int>> cache(n + 2, vector<int>(n + 2, kInf));
    
    function<int(int, int)> dp = [&](int l, int r) {
      int &ans = cache[l][r];
      if (l >= r)
        return 0;
      if (ans != kInf)
        return ans;
      for (int x = l; x <= r; ++x)
        ans = min(ans, x + max(dp(l, x - 1), dp(x + 1, r)));
      return ans;
    };

    return dp(1, n);
  }
};