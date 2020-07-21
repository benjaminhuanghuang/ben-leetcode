/*
395. Longest Substring with At Least K Repeating Characters

Level: Medium

https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters
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

class Solution
{
public:
  int longestSubstring(string s, int k)
  {
    int res = 0, i = 0, n = s.size();

    while (i + k <= n)
    {
      int m[26]{0};
      int mask = 0, max_idx = i;
      for (int j = i; j < n; ++j)
      {
        int t = s[j] - 'a';
        ++m[t];
        if (m[t] < k)
          mask |= (1 << t);
        else
          mask &= (~(1 << t));
        if (mask == 0)
        {
          res = max(res, j - i + 1);
          max_idx = j;
        }
      }
      i = max_idx + 1;
    }
    return res;
  }
};