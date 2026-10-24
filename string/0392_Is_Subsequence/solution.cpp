/*
392. Is Subsequence

Level: Easy

https://leetcode.com/problems/is-subsequence
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

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
  bool isSubsequence(string s, string t)
  {
    if (s.size() == 0)
      return true;
    int i = 0, j = 0;
    while (i < s.size() && j < t.size())
    {
      if (s[i] == t[j])
      {
        ++i;
        ++j;
      }
      else
      {
        ++j;
      }
    }
    return i == s.size();
  }
};