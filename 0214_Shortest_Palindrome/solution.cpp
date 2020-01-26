/*
214. Shortest Palindrome

https://leetcode.com/problems/shortest-palindrome/
给你一个字符串你可以在它的前面添加一些字符，返回最短的回文字符串。
 */
#include <string>
#include <vector>

using namespace std;
/*
https://zxi.mytechroad.com/blog/string/leetcode-214-shortest-palindrome/
reversed + s 肯定是一个Palindrome， 需要想办法去掉reversed 和s 中的公共部分
s:        abcd
reversed: dcba
result:   dcbabcd
 */
class Solution_MemoryLimit
{
public:
  string shortestPalindrome(string s)
  {
    const string reversed(s.rbegin(), s.rend());
    const int n = s.size();
    for (int i = 0; i < n; ++i)
    {
      if (s.substr(0, n - i) == reversed.substr(i)) // Memory Limit Exceeded
      {
        // s开头的一部分 == reversed 结尾的一部分,
        return reversed.substr(0, i) + s;
      }
    }
    return "";
  }
};
/*
"aaaaaa..."
 */
class Solution_Error
{
public:
  string shortestPalindrome(string s)
  {
    string reversed(s.rbegin(), s.rend());
    const int n = s.size();
    for (int i = 0; i < n; ++i)
    {
      //if (s.substr(0, n - i) == reversed.substr(i))  // memory issue
      if (stringEqual(s, 0, n - i, reversed, i, n - 1))
      {
        // s开头的一部分 == reversed 结尾的一部分,
        return reversed.substr(0, i) + s;
      }
    }
    return "";
  }

private:
  bool stringEqual(string &str1, int start1, int end1, string &str2, int start2, int end2)
  {
    int i1 = start1;
    int i2 = start2;
    while (i1 <= end1 && i2 < end2)
    {
      if (str1[i1++] != str2[i2++])
      {
        return false;
      }
    }
    return true;
  }
};

class Solution
{
public:
  string shortestPalindrome(string s)
  {
    string r(s.rbegin(), s.rend());
    string t = s + "#" + r;
    vector<int> next(t.size(), 0);
    for (int i = 1; i < t.size(); ++i)
    {
      int j = next[i - 1];
      while (j > 0 && t[i] != t[j])
        j = next[j - 1];
      next[i] = (j += t[i] == t[j]);
    }
    return r.substr(0, s.size() - next.back()) + s;
  }
};