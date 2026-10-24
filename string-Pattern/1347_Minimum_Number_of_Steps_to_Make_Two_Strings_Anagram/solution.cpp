/*
1347. Minimum Number of Steps to Make Two Strings Anagram

Level: Medium

https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram
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
  int minSteps(string s, string t)
  {

    int n = s.size();

    if (n < 1)
    {
      return 0;
    }
    unordered_map<char, int> map;

    for (int i = 0; i < n; i++)
    {
      char a = s[i], b = t[i];

      map[a]++;
      map[b]--;
    }
    int res = 0;
    for (auto kv : map)
    {
      res += abs(kv.second);
    }
    return res / 2;
  }
};