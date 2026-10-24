/*
459. Repeated Substring Pattern

https://leetcode.com/problems/repeated-substring-pattern/
*/
#include <string>

using namespace std;

class Solution
{
public:
  bool repeatedSubstringPattern(string s)
  {
    int n = s.size();
    for (int len = n / 2; len >= 1; --len)
    {
      if (n % len == 0)
      {
        int count = n / len;
        string t = "";
        for (int j = 0; j < count; ++j)
        {
          t += s.substr(0, len);
        }
        if (t == s)
          return true;
      }
    }
    return false;
  }
};

class Solution
{
public:
  bool repeatedSubstringPattern(string s)
  {
    return (s + s).substr(1, s.size() * 2 - 2).find(s) != -1;
  }
};