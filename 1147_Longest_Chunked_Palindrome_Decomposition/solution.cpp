/*
1147. Longest Chunked Palindrome Decomposition

Level: Hard

https://leetcode.com/problems/longest-chunked-palindrome-decomposition
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
  Solution: Recursion
  https://zxi.mytechroad.com/blog/string/leetcode-1147-longest-chunked-palindrome-decomposition/

  Time complexity: O(n^2)
  Space complexity: O(n)
*/

class Solution
{
public:
  int longestDecomposition(string text)
  {
    const int n = text.length();
    if (n == 0)
      return 0;
    for (int l = 1; l <= n / 2; ++l)
    {
      if (text.substr(0, l) == text.substr(n - l))
        return 2 + longestDecomposition(text.substr(l, n - 2 * l));
    }
    return 1;
  }
};