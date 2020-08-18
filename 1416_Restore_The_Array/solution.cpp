/*
1416. Restore The Array

Level: Hard

https://leetcode.com/problems/restore-the-array
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

class Solution
{
public:
  bool hasAllCodes(string s, int k)
  {
    bitset<1 << 20> set;
    int value = 0;

    for (int i = 0; i < s.size(); i++)
    {
      value <<= 1;
      value |= s[i] - '0';
      value &= (1 << k) - 1;

      if (i + 1 >= k)
      {
        set[value] = 1;
      }
    }

    return set.count() == (1 << k);
  }
};

/*
  Solution: 
  https://zxi.mytechroad.com/blog/hashtable/leetcode-1461-check-if-a-string-contains-all-binary-codes-of-size-k/
  Insert all possible substrings into a hashtable, the size of the hashtable should be 2^k.
*/

class Solution
{
public:
  int numberOfArrays(string s, int k)
  {
    const int n = s.length();
    if ((n - k + 1) * k < (1 << k))
      return false;
    unordered_set<string_view> c;
    for (int i = 0; i + k <= n; ++i)
      c.insert(s.substr(i, k));
    return c.size() == (1 << k);
  }
};