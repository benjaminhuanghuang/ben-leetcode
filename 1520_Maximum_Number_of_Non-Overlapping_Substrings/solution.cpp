/*
1520. Maximum Number of Non-Overlapping Substrings

Level: Medium

https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings
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
  https://zxi.mytechroad.com/blog/greedy/leetcode-1520-maximum-number-of-non-overlapping-substrings/
*/

class Solution
{
public:
  vector<string> maxNumOfSubstrings(string s)
  {
    const int n = s.length();
    vector<int> l(26, INT_MAX);
    vector<int> r(26, INT_MIN);
    for (int i = 0; i < n; ++i)
    {
      l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
      r[s[i] - 'a'] = max(r[s[i] - 'a'], i);
    }
    auto extend = [&](int i) -> int {
      int p = r[s[i] - 'a'];
      for (int j = i; j <= p; ++j)
      {
        if (l[s[j] - 'a'] < i) // invalid substring
          return -1;           // e.g. a|"ba"...b
        p = max(p, r[s[j] - 'a']);
      }
      return p;
    };

    vector<string> ans;
    int last = -1;
    for (int i = 0; i < n; ++i)
    {
      if (i != l[s[i] - 'a'])
        continue;
      int p = extend(i);
      if (p == -1)
        continue;
      if (i > last)
        ans.push_back("");
      ans.back() = s.substr(i, p - i + 1);
      last = p;
    }
    return ans;
  }
};