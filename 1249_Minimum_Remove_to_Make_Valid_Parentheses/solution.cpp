/*
1249. Minimum Remove to Make Valid Parentheses

Level: Medium

https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses
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
  Count how many “(” are open and how many “)” left.
*/

class Solution
{
public:
  string minRemoveToMakeValid(string s)
  {
    int close = count(begin(s), end(s), ')');
    int open = 0;
    string ans;

    for (char c : s)
    {
      if (c == '(')
      {
        if (open == close)
          continue;
        ++open;
      }
      else if (c == ')')
      {
        --close;
        if (open == 0)
          continue;
        --open;
      }
      ans += c;
    }
    return ans;
  }
};