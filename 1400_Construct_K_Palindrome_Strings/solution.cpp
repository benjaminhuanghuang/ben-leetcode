/*
1400. Construct K Palindrome Strings

Level: Medium

https://leetcode.com/problems/construct-k-palindrome-strings
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
  Compute the frequency of each characters.

  Count the # of characters with odd frequency |odd|, 
   each palindrome can consume at most one char with odd frequency. thus k must >= |odd|.
  ans = k <= len(s) and k >= odd

  Time complexity: O(n)
  Space complexity: O(1)
*/

class Solution
{
public:
  bool canConstruct(string s, int k)
  {
    if (k > s.length())
      return false;
    vector<int> f(26);
    for (char c : s)
      f[c - 'a'] ^= 1;

    int odd = accumulate(begin(f), end(f), 0);
    return k >= odd;
  }
};