/*
434. Number of Segments in a String

https://leetcode.com/problems/number-of-segments-in-a-string/
*/
#include <string>

using namespace std;

class Solution
{
public:
  int countSegments(string s)
  {
    if (s.empty())
      return 0;
    int ans = 0;
    int i = 0;
    while (i < s.length())
    {
      // skip ' 's
      while (i < s.length() && s[i] == ' ')
        ++i;
      if (i == s.length())
        break;
      // skip letters
      while (i < s.length() && s[i] != ' ')
        ++i;
      ++ans;
      ++i;
    }
    return ans;
  }
};