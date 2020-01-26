/*
1071. Greatest Common Divisor of Strings

https://leetcode.com/problems/greatest-common-divisor-of-strings/

For strings S and T, we say "T divides S" if and only if S = T + ... + T  (T concatenated with itself 1 or more times)

Return the largest string X such that X divides str1 and X divides str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
 

Note:

1 <= str1.length <= 1000
1 <= str2.length <= 1000
str1[i] and str2[i] are English uppercase letters.
*/
#include <numeric>
#include <string>

using namespace std;

/*
Brute-Force
注意：题目已经保证str1 和 str2 由T的重复出现构成
*/
class Solution
{
public:
  string gcdOfStrings(string str1, string str2, int len = 0)
  {
    auto sz1 = str1.size(), sz2 = str2.size();
    for (auto i = min(sz1, sz2); i >= 1; i--)
    {
      if (sz1 % i == 0 && sz2 % i == 0)
      {
        string T = str1.substr(0, i), s1, s2;
        for (auto j = 0; j < sz1 / i; ++j)
          s1 += T;
        for (auto j = 0; j < sz2 / i; ++j)
          s2 += T;
        if (s1 == str1 && s2 == str2)
        {
          len = i;
          break;
        }  
      }
    }
    return str1.substr(0, len);
  }
};

class Solution_Better
{
public:
  string gcdOfStrings(string str1, string str2)
  {
    int n = str1.size(), m = str2.size();
    string res = "";
    int gc = gcd(n, m);   // numeric lib
    for (int i = 0; i < gc; i++)
    {
      if (str1[i] != str2[i])
        return "";
      res += str1[i];
    }
    return res;
  }
};

/*
DP, Error
*/
#include <vector>
class Solution_DP_Error
{
public:
  string gcdOfStrings(string str1, string str2)
  {
    vector<vector<int>> dp = vector<vector<int>>(str1.size(), vector<int>(str2.size(), 0));

    int longest = 0;
    int x_longest = 0;

    for (int x = 1; x <= str1.size(); x++)
    {
      for (int y = 1; y <= str2.size(); y++)
      {
        if (str1[x - 1] == str2[y - 1])
        {
          dp[x][y] = dp[x - 1][y - 1] + 1;
          if (dp[x][y] > longest)
          {
            longest = dp[x][y];
            x_longest = x;
          }
        }
        else
        {
          dp[x][y] = 0;
        }
      }
    }
    return str1.substr(x_longest - longest, longest);
  }
};