/*
242. Valid Anagram

Level: Easy

https://leetcode.com/problems/valid-anagram
*/
#include <vector>
#include <string>
#include <unordered_map>

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
  bool isAnagram(string s, string t)
  {
    unordered_map<char, int> counter;

    for (auto c : s)
    {
      counter[c]++;
    }

    for (auto c : t)
    {
      if (counter[c] == 0)
      {
        return false;
      }
      counter[c]--;
    }

    for (auto kv : counter)
    {
      if (kv.second > 0)
      {
        return false;
      }
    }
    return true;
  }

  bool isAnagram_v2(string s, string t)
  {
    vector<int> a(26), b(26);
    for (char c : s)
      a[c - 'a']++;
    for (char c : t)
      b[c - 'a']++;
    for (int i = 0; i < 26; i++)
    {
      if (a[i] != b[i])
        return false;
    }
    return true;
  }
};