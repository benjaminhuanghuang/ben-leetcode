/*
32. Longest Valid Parentheses

https://leetcode.com/problems/longest-valid-parentheses/
 */

#include <vector>
#include <string>
#include <stack>

using namespace std;

/*
https://zxi.mytechroad.com/blog/stack/leetcode-32-longest-valid-parentheses/

Use a stack to track the index of all unmatched open parentheses.

Time complexity: O(n)

Space complexity: O(n)

 */
class Solution
{
public:
  int longestValidParentheses(string s)
  {
    stack<int> q;
    int start = 0;
    int maxLen = 0;
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == '(')
      {
        q.push(i);
      }
      else  // ')'
      {
        if (q.empty())
        {
          start = i + 1;
        }
        else
        {
          int index = q.top();
          q.pop();
          // whenever stack pop, compare its length to the global max length.
          maxLen = max(maxLen, q.empty() ? i - start + 1 : i - q.top());
        }
      }
    }
    return maxLen;
  }
};
/*
dp[i]表示以当前位置为终点的最长长度，则只能在）处更新，

如果s[i-1-dp[i-1]]=='('，则说明当前位置可以和i-1-dp[i-1]位置匹配，dp[i]=dp[i-1]+2;

然后还要加上匹配位置之前的最长长度dp[i]+=dp[i-dp[i]];
 */
class Solution
{
public:
  int longestValidParentheses(string s)
  {
    if (s.empty())
      return 0;
    int result = 0;
    s = ')' + s;
    vector<int> dp(s.length(), 0);
    for (int i = 1; i < s.length(); i++)
    {
      if (s[i] == ')')
      {
        if (s[i - 1 - dp[i - 1]] == '(')
          dp[i] = dp[i - 1] + 2;
        dp[i] += dp[i - dp[i]];
      }
      result = max(result, dp[i]);
    }
    return result;
  }
};