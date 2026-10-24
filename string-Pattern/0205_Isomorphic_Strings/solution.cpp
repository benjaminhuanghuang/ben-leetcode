/*
205. Isomorphic Strings

Level: Easy

https://leetcode.com/problems/isomorphic-strings
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
  bool isIsomorphic(string s, string t)
  {
    unordered_map<char, char> res, st;
    for (int i = 0; i < s.length(); i++)
    {
      if (res.count(s[i]) || st.count(t[i]))
      {
        if (res[s[i]] != t[i] || st[t[i]] != s[i])
        {
          return false;
        }
      }
      else
      {
        res[s[i]] = t[i];
        st[t[i]] = s[i];
      }
    }
    return true;
  }
};

class Solution
{
public:
  bool isIsomorphic(string s, string t)
  {
    int m1[256] = {0}, m2[256] = {0}, n = s.size();
    for (int i = 0; i < n; ++i)
    {
      if (m1[s[i]] != m2[t[i]])
        return false;
      m1[s[i]] = i + 1;
      m2[t[i]] = i + 1;
    }
    return true;
  }
};

class Solution
{
public:
  bool isIsomorphic(string s, string t)
  {
    if (s.size() != t.size())
      return false;

    unordered_map<char, char> stMap;
    unordered_map<char, char> tsMap;

    for (int i = 0; i < s.length(); i++)
    {
      char cs = s[i];
      char ct = t[i];

      if (stMap.count(cs) == 0)
      {
        stMap[cs] = ct;
      }
      else
      {
        if (stMap[cs] != ct)
        {
          return false;
        }
      }

      if (tsMap.count(ct) == 0)
      {
        tsMap[ct] = cs;
      }
      else
      {
        if (tsMap[ct] != cs)
        {
          return false;
        }
      }
    }
    return true;
  }

  bool isIsomorphic(string s, string t)
  {
    int a1[256] = {0}, a2[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
      a1[s[i]] += i + 1;
      a2[t[i]] += i + 1;
    }
    for (int i = 0; i < s.size(); i++)
      if (a1[s[i]] != a2[t[i]])
        return 0;

    return 1;
  }
};