package cn.huang.leetcode;

import java.util.Stack;

/*
32. Longest Valid Parentheses

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"


 */
public class LC_0032_LongestValidParentheses {
    public int longestValidParentheses(String s) {
        int maxLength = 0;
        Stack<Integer> stack = new Stack<Integer>();

        for (int i = 0; i < s.length(); i++)
        {
            if (s.charAt(i) == '(')
                stack.push(i);
            else
            {
                // ')'
                if (!stack.isEmpty() && s.charAt(stack.peek()) == '(')
                {
                    stack.pop();
                    // whenever stack pop, compare its length to the global max length.
                    int newLen = i - (!stack.isEmpty() ? stack.peek() : -1);
                    maxLength = Math.max(maxLength, newLen);
                }
                else
                {
                    stack.push(i);
                }
            }
        }
        return maxLength;
    }

    public int LongestValidParentheses_DP(String s)
    {
        if (s== null) return 0;
        int[] dp = new int[s.length()];
        dp[0] = 0;

        for (int i = 1; i < s.length(); i++)
        {
            if (s.charAt(i) == '(')
                dp[i] = 0;
            else
            {
                int pre = i - dp[i - 1] - 1;
                if (pre >= 0 && s.charAt(pre) == '(')
                {
                    dp[i] += dp[i - 1] + 2;
                    pre--;
                    if (pre >= 0)
                    {
                        dp[i] += dp[pre];
                    }
                }
                else dp[i] = 0;
            }
        }
        int max = Integer.MIN_VALUE;
        for(int i : dp)
        {
            max = Math.max(max, dp[i]);
        }
        return max;
    }
}
