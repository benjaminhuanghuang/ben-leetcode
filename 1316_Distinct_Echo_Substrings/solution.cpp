/*
1316. Distinct Echo Substrings

Level: Hard

https://leetcode.com/problems/distinct-echo-substrings
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
  Solution:  Brute Force + HashSet

    Try all possible substrings

    Time complexity: O(n^3)
    Space complexity: O(n^2)
*/

class Solution
{
public:
  int distinctEchoSubstrings(string text)
  {
    const int n = text.length();
    string_view t(text);
    unordered_set<string_view> s;
    for (int k = 1; k <= n / 2; ++k)
      for (int i = 0; i + k <= n; ++i)
        if (t.substr(i, k) == t.substr(i + k, k))
          s.insert(t.substr(i, 2 * k));
    return s.size();
  }
};