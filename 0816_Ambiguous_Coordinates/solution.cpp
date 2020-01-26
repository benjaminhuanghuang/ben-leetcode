/*
816. Ambiguous Coordinates

https://leetcode.com/problems/ambiguous-coordinates/

把一串数字分成两段，输出所有合法的分法（可以加小数点）。
*/
#include <vector>
#include <string>

using namespace std;
/*
https://zxi.mytechroad.com/blog/string/leetcode-816-ambiguous-coordinates/

Solution: Brute Force

Time complexity: O(n^3)

Space complexity: O(n)
*/
class Solution
{
public:
  vector<string> ambiguousCoordinates(string S)
  {
    vector<string> ans;
    int n = S.length();
    for (int l1 = 1; l1 <= n - 3; ++l1)
    {
      int l2 = n - l1 - 2;
      string s1 = S.substr(1, l1);
      string s2 = S.substr(l1 + 1, l2);
      if (valid(s1) && valid(s2))
        ans.push_back("(" + s1 + ", " + s2 + ")");

      for (int i = 0; i < l1; ++i)
      {
        string ts1 = s1;
        if (i > 0)
          ts1.insert(i, ".");
        if (!valid(ts1))
          continue;
        for (int j = 0; j < l2; ++j)
        {
          if (i == 0 && j == 0)
            continue;
          string ts2 = s2;
          if (j > 0)
            ts2.insert(j, ".");
          if (!valid(ts2))
            continue;
          ans.push_back("(" + ts1 + ", " + ts2 + ")");
        }
      }
    }

    return ans;
  }

private:
  bool valid(const string &s)
  {
    bool p = false; // has "."
    bool d = false; // has digits in front of "."
    int zeros = 0;  // leading zeros
    int i = 0;
    while (s[zeros] == '0' && zeros < s.length())
      ++zeros;
    for (int i = zeros; i < s.length(); ++i)
    {
      if (!p && isdigit(s[i]))
        d = true;
      if (s[i] == '.')
        p = true;
    }
    if (zeros == 1 && s != "0" && !p || zeros > 1)
      return false;
    if (p && (s.back() == '0' || s.back() == '.' || zeros > 0 && d))
      return false;
    return true;
  }
};

/*
https://www.cnblogs.com/grandyang/p/9563418.html
*/
class Solution
{
public:
  vector<string> ambiguousCoordinates(string S)
  {
    vector<string> res;
    int n = S.size();
    for (int i = 1; i < n - 2; ++i)
    {
      vector<string> A = findAll(S.substr(1, i)), B = findAll(S.substr(i + 1, n - 2 - i));
      for (auto &a : A)
      {
        for (auto &b : B)
        {
          res.push_back("(" + a + ", " + b + ")");
        }
      }
    }
    return res;
  }
  vector<string> findAll(string S)
  {
    int n = S.size();
    if (n == 0 || (n > 1 && S[0] == '0' && S[n - 1] == '0'))
      return {};
    if (n > 1 && S[0] == '0')
      return {"0." + S.substr(1)};
    if (S[n - 1] == '0')
      return {S};
    vector<string> res{S};
    for (int i = 1; i < n; ++i)
      res.push_back(S.substr(0, i) + "." + S.substr(i));
    return res;
  }
};