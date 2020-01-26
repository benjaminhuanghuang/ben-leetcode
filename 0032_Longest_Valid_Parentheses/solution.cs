/*
32. Longest Valid Parentheses

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

reference
    https://miafish.wordpress.com/2015/05/02/leetcode-ojc-longest-valid-parentheses/
*/
using System;
using System.Collections.Generic;
using System.Linq;

public class Solution032 {
    public int LongestValidParentheses_Stack(string s) {
        var maxLength = 0;
        var stack = new Stack<int>();

        for (int i = 0; i < s.Length; i++)
        {
            if (s[i] == '(') 
                stack.Push(i);
            else
            {
                // ')'
                if (stack.Any() && s[stack.Peek()] == '(')
                {
                    stack.Pop();
                    // whenever stack pop, compare its length to the global max length.
                    int newLen = i - (stack.Any() ? stack.Peek() : -1);
                    maxLength = Math.Max(maxLength, newLen);
                }
                else
                {
                    stack.Push(i);
                }
            }
        }
        return maxLength; 
    }

    public int LongestValidParentheses_DP(string s)
    {
        if (string.IsNullOrEmpty(s)) return 0;
        var dp = new int[s.Length];
        dp[0] = 0;

        for (int i = 1; i < s.Length; i++)             
        {                 
            if (s[i] == '(') 
                dp[i] = 0;                 
            else                 
            {                     
                var pre = i - dp[i - 1] - 1;                     
                if (pre >= 0 && s[pre] == '(')
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

        return dp.Max();
    }
}