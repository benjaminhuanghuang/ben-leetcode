/*
1163. Last Substring in Lexicographical Order

Level: Hard

https://leetcode.com/problems/last-substring-in-lexicographical-order
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
  string lastSubstring_bruteforce(string s)
  {
    string_view ans;
    for (int i = 0; i < s.length(); ++i)
      if (s.substr(i) > ans)
        ans = s.substr(i);
    return string(ans);
  }

  string lastSubstring_bruteforce2(string s)
  {
    double ex = 0.0, pre = 0.0;

    int idx = 0;

    for (int i = s.size() - 1; i >= 0; i--)
    {
      double cur = pre / 26.0 + s[i] - 'a';
      if (cur > ex)
      {
        ex = cur;
        idx = i;
      }
      pre = cur;
    }
    return s.substr(idx);
  }
};