/*
44. Wildcard Matching

https://leetcode.com/problems/wildcard-matching/
*/
#include <string>

using namespace std;

/*
https://www.youtube.com/watch?v=-8QnRMyHo_o
*/
class Solution
{
public:
  bool isMatch(string s, string p)
  {
    int sp = 0;
    int pp = 0;
    int match = 0;
    int start = -1; // start pos of *
    while (sp < s.length())
    {
      // match single char
      if (pp < p.length() && (s[sp] == p[pp] || p[pp] == '?'))
      {
        sp++;
        pp++;
      }
      else if (pp < p.length() && p[pp] == '*')
      {
        start = pp;
        match = sp;
        pp++;
      }
      else if (start != -1)
      {
        pp = start + 1;
        match++;
        sp = match;
      }
      else
        return false;
    }
    while (pp < p.length() && p[pp] == '*')
    {
      pp++;
    }
    return pp == p.length();
  }
};