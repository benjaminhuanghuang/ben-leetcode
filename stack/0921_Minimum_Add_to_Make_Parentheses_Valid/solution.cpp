/*
921. Minimum Add to Make Parentheses Valid

Level: Medium

https://leetcode.com/problems/minimum-add-to-make-parentheses-valid
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
  int minAddToMakeValid(string S)
  {
    int l = 0;
    int match = 0;
    for (char c : S)
    {
      if (c == '(')
        ++l;
      if (c == ')' && l > 0)
      {
        --l;
        ++match;
      }
    }
    return S.size() - match * 2;
  }
};