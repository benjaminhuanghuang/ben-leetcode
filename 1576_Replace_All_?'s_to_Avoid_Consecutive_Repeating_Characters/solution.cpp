/*
1576. Replace All ?'s to Avoid Consecutive Repeating Characters

Level: Easy

https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters
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
*/

class Solution
{
public:
  string modifyString(string s)
  {
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
      if (s[i] == '?')
      {
        // select a candidate from a, b, c to replace ?s
        for (int j = 0; j < 3; j++)
        {
          char candidate = 'a' + j;
          if (i > 0 && s[i - 1] == candidate || i < len - 1 && s[i + 1] == candidate)
          {
            continue;
          }
          else
          {
            s[i] = candidate;
            break;
          }
        }
      }
    }
    return s;
  }
};