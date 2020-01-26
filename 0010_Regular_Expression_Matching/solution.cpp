/*
10. Regular Expression Matching

https://leetcode.com/problems/regular-expression-matching/
*/

#include <string>

using namespace std;

/*
https://zxi.mytechroad.com/blog/searching/leetcode-10-regular-expression-matching/

Time complexity: O((|s| + |p|) * 2 ^ (|s| + |p|))
Space complexity: O(|s| + |p|)
*/
class Solution
{
public:
  bool isMatch(string s, string p)
  {
    return isMatch(s.c_str(), p.c_str());
  }

private:
  bool isMatch(const char *s, const char *p)
  {
    if (*p == '\0')
      return *s == '\0';

    // normal case, e.g. 'a.b','aaa', 'a'
    if (p[1] != '*' || p[1] == '\0')
    {
      // no char to match
      if (*s == '\0')
        return false;

      if (*s == *p || *p == '.')
        return isMatch(s + 1, p + 1);
      else
        return false;
    }
    else
    {
      int i = -1;
      while (i == -1 || s[i] == p[0] || p[0] == '.')
      {
        if (isMatch(s + i + 1, p + 2))
          return true;
        if (s[++i] == '\0')
          break;
      }
      return false;
    }

    return false;
  }
};