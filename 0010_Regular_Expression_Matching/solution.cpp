/*
10. Regular Expression Matching

https://leetcode.com/problems/regular-expression-matching/
*/

#include <string>

using namespace std;

/*
DP
f[i][j]表示 s[0..i-1] 是否匹配p[0..j-1]

if p[j - 1] != '*'

     f[i][j] = f[i-1][j-1]&& (p[j-1]=='.'||s[i-1]==p[j-1])

if p[j - 1] == '*', 设 p[j - 2] 为 x

      1) "x*" 重复0次：f[i][j] = f[i][j - 2]

      2)"x*" 重复1次以上：f[i][j] = f[i-1][j] && (p[j-2]=='.'||s[i-1]==p[j-2])


*/
bool isMatch(string s, string p)
{
    int m=s.length(), n=p.length();
    bool f[m+1][n+1];
    f[0][0] = 1;

    for(int i=1; i<=m; ++i)
        f[i][0] = 0;

    for(int i=1; i<=n; ++i)
        if(p[i-1]!='*')
            f[0][i] = 0;
        else
            f[0][i] = f[0][i-2];
            
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
        {
            if(p[j-1]!='*')
                f[i][j] = f[i-1][j-1]&& (p[j-1]=='.'||s[i-1]==p[j-1]);
            else
                f[i][j] = f[i][j-2] || (f[i-1][j]&& (p[j-2]=='.'||s[i-1]==p[j-2]));
        }
    return f[m][n];
}

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