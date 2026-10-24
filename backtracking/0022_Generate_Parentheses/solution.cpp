/*
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

https://leetcode.com/problems/generate-parentheses/
*/

#include <vector>
#include <string>

using namespace std;
/*
  这道题不是back-tracking
*/
class Solution
{
public:
  vector<string> generateParenthesis(int n)
  {
    vector<string> ans;
    string cur;
    if (n > 0)
      dfs(n, n, cur, ans);
    return ans;
  }

private:
  void dfs(int l, int r, string s, vector<string> &ans)
  {
    if (l == 0 && r == 0)
    {
      ans.push_back(s);
      return;
    }
    if (l > 0)
    {
      dfs(l - 1, r, s + "(", ans);
    }
    if (r > l)
    {
      dfs(l, r - 1, s + ")", ans);
    }
  }
};