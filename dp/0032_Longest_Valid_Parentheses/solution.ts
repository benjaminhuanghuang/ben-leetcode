/*
32. Longest Valid Parentheses

https://leetcode.com/problems/longest-valid-parentheses/
*/

/*
dp
dp[i]表示以当前位置为终点的最长长度，则只能在）处更新，

如果s[i-1-dp[i-1]]=='('，则说明当前位置可以和i-1-dp[i-1]位置匹配，dp[i]=dp[i-1]+2;

然后还要加上匹配位置之前的最长长度dp[i]+=dp[i-dp[i]];
*/

/*
https://zxi.mytechroad.com/blog/stack/leetcode-32-longest-valid-parentheses/

Use a stack to track the index of all unmatched open parentheses.

Time complexity: O(n)

Space complexity: O(n)

 */

function longestValidParentheses(s: string): number {
  if (s.length === 0) return 0;

  let result = 0;
  s = ")" + s; // Add a ')' at the beginning of the string
  const dp = new Array(s.length).fill(0);

  for (let i = 1; i < s.length; i++) {
    if (s[i] === ")") {
      if (s[i - 1 - dp[i - 1]] === "(") {
        dp[i] = dp[i - 1] + 2;
      }
      dp[i] += dp[i - dp[i]];
    }
    result = Math.max(result, dp[i]);
  }

  return result;
}
