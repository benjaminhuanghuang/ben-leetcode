/*
1541. Minimum Insertions to Balance a Parentheses String

Level: Medium

https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string
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
  https://zxi.mytechroad.com/blog/string/leetcode-1541-minimum-insertions-to-balance-a-parentheses-string/
*/

class Solution
{
public:
  int minInsertions(string s)
  {
    int ans = 0;
    int close = 0; // # of ')' needed.
    for (char c : s)
    {
      if (c == ')')
      {
        if (--close < 0)
        {
          // need to insert one '('
          // ')' -> '()'
          ++ans;
          close += 2;
        }
      }
      else
      {
        if (close & 1)
        {
          // need to insert one ')'
          // case '(()(' -> '(())('
          --close;
          ++ans;
        }
        close += 2; // need two ')'s
      }
    }
    return ans + close;
  }
};