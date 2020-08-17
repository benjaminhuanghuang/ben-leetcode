/*
1208. Get Equal Substrings Within Budget

Level: Medium

https://leetcode.com/problems/get-equal-substrings-within-budget
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
  求一个数组的子序列，这个子序列要满足和小于maxCost，并且在所有满足和小于maxCost的子序列中长度最长。

  Solution: Sliding Window

    Time complexity: O(n)
    Space complexity: O(1)
*/

class Solution
{
public:
  int equalSubstring(string s, string t, int maxCost)
  {
    const int n = s.length();
    int ans = 0;
    for (int i = 0, j = 0, cost = 0; i < n && j < n; ++i)
    {
      while (j < n)
      {
        int c = abs(s[j] - t[j]);
        if (cost + c > maxCost)
          break;
        cost += c;
        ++j;
      }
      ans = max(ans, j - i);
      cost -= abs(s[i] - t[i]);
    }
    return ans;
  }
};