/*
14. Longest Common Prefix

https://leetcode.com/problems/longest-common-prefix/
*/
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    if (strs.empty())
      return "";
    string ans;
    // based on strs[0]
    for (int i = 0; i < strs[0].size(); ++i)
    {
      for (const string &s : strs)
        if (s.length() <= i || s[i] != strs[0][i])
          return ans;
      ans += strs[0][i];
    }
    return ans;
  }
};