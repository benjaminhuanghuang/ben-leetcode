/*
91. Decode Ways

https://leetcode.com/problems/decode-ways/

一个加密的数字字符串，一共有多少种不同的解密方式。
*/

#include <string>
#include <vector>

using namespace std;
/*
  It's the easiest solution to understand.
  dp[i] 表示i个字符可以有几个解 
  dp[0] 表示 empty string """

  对于s[i], 有几种可能：
  如果s[i]=='0' s[i]不能单独作为一个字符，只能s[i-1,i] 放在一起才合法，此时s[i] = s[i-2]
  如果s[i]!='0' s[i]可以单独作为一个字符，此时s[i] = s[i-1]
  如果s[i-1]=='0' s[i-1...i]不合法，此时s[i] = s[i-1]
  如果s[i-1...i] 是一个合法的两位数字即10 to 26 此时 s[i] = s[i-1] + s[i-2] 
  
*/
class Solution
{
public:
  int numDecodings(string s)
  {
    if (s.empty() || s[0] == '0')
      return 0;
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < dp.size(); ++i)
    {
      int way = 0;
      if(s[i - 1] != '0')   // treat s[i] as a single number, need check s[i-1] 
        way += dp[i - 1];
      if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
        way += dp[i - 2];
      dp[i] = way;
    }
    return dp.back();
  }
};

/*
  huahua
*/
class Solution
{
public:
  int numDecodings(string s)
  {
    if (s.empty() || s[0] == '0')
      return 0;
    if (s.length() == 1)
      return 1;

    const int n = s.length();
    int w1 = 1;
    int w2 = 1;
    for (int i = 1; i < n; ++i)
    {
      int w = 0;
      if (!isValid(s[i]) && !isValid(s[i - 1], s[i]))
        return 0;
      if (isValid(s[i]))
        w = w1;
      if (isValid(s[i - 1], s[i]))
        w += w2;
      w2 = w1;
      w1 = w;
    }
    return w1;
  }

private:
  bool isValid(const char c) { return c != '0'; }
  bool isValid(const char c1, const char c2)
  {
    const int num = (c1 - '0') * 10 + (c2 - '0');
    return num >= 10 && num <= 26;
  }
};

/*
  Recursion + Memorization
  Time O(1) * (N+1) = O(N) string length
  Space O(N)  
*/
class Solution
{
public:
  int numDecodings(string s)
  {
    if (s.empty() || s[0] == '0')
      return 0;

    if (s.length() == 1)
      return 1;
    vector<int> m(s.length(), -1);
    return numDecodings(s, 0, m);
  }

private:
  int numDecodings(string &s, int level, vector<int> &m)
  {
    if (m[level] != -1)
    {
      return m[level];
    }

    if (level == s.length())
    {
      m[level] = 1;
      return 1;
    }
    int ways = 0;
    if (s[level] != '0') // '1' to '9', can be decode
    {
      ways += numDecodings(s, level + 1, m);
    }
    if (validEndoding(s, level))
    { // '10'to'26'
      ways += numDecodings(s, level + 2, m);
    }
    m[level] = ways;
    return ways;
  }

  bool validEndoding(string &s, int start)
  {
    if (start + 1 >= s.size())
      return false;
    if (s[start] == '1')
      return true;
    return (s[start] == '2' && s[start + 1] - '6' <= 0);
  }
};
/*
Lai Offer
https://www.youtube.com/watch?v=ZLwwc3-vVP4&t=74s

Bottom to To DP
 */
class Solution
{
public:
  int numDecodings(string s)
  {
    if (s.empty() || s[0] == '0')
      return 0;
    int n = s.length();
    if (n == 1)
      return 1;

    vector<int> dp(n);
    dp[n - 1] = 1;

    if (stoi(s.substr(0, 2)) > 26)
    {
      if (s[1] != '0')
      {
        dp[1] = 1;
      }
      else
      {
        dp[1] = 0;
      }
    }
    else
    {
      if (s[1] != '0')
      {
        dp[1] = 2;
      }
      else
      {
        dp[1] = 1;
      }
    }

    for (int i = 2; i < s.length(); i++)
    {
      if (s[i] != '0')
      {
        dp[i] += dp[i - 1];
      }

      int val = stoi(s.substr(i - 1, 2));
      if (val <= 26 && val >= 10)
      {
        dp[i] += dp[i - 2];
      }
    }

    return dp[s.length() - 1];
  }
};
