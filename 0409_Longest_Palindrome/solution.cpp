/*
409. Longest Palindrome

Level: Easy

https://leetcode.com/problems/longest-palindrome
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
  用hashtable记录每个字符出现的次数，出现偶数次的字符和一个出现奇数次的字符可以构成Palindrome
*/

class Solution
{
public:
  int longestPalindrome(string s)
  {
    unordered_map<char, int> dict;

    for (int i = 0; i < s.size(); i++)
    {
      dict[s[i]]++;
    }
    int res = 0;
    bool hasSingle = false;
    for (auto kv : dict)
    {
      if (kv.second & 1)
      {
        hasSingle = true;
      }
      res += kv.second / 2;
    }
    res = res * 2;
    if (hasSingle)
      res++;
    return res;
  }
};