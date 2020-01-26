/*
522. Longest Uncommon Subsequence II
https://leetcode.com/problems/longest-uncommon-subsequence-ii/
*/

#include <string>
#include <vector>

using namespace std;
/*
Brute force
遍历所有的字符串，对于每个遍历到的字符串，再和所有的其他的字符串比较，看是不是某一个字符串的子序列，如果都不是的话，那么当前字符串就是一个非共同子序列，用其长度来更新结果res
*/
class Solution
{
public:
  int findLUSlength(vector<string> &strs)
  {
    int res = -1, j = 0, n = strs.size();
    for (int i = 0; i < n; ++i)
    {
      for (j = 0; j < n; ++j)
      {
        if (i == j)
          continue;
        if (checkSubs(strs[i], strs[j]))
          break;
      }
      if (j == n)
        res = max(res, (int)strs[i].size());
    }
    return res;
  }

private:
  int checkSubs(string subs, string str)
  {
    int i = 0;
    for (char c : str)
    {
      if (c == subs[i])
        ++i;
      if (i == subs.size())
        break;
    }
    return i == subs.size();
  }
};