# 22. Generate Parentheses

https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

Algorithm:
Keep track of counts of open and close brackets. Initialize these counts as 0.
Recursively call the printParenthesis() function until open bracket count is less than the given n.

If open bracket count becomes more than the close bracket count, then put a closing bracket and
recursively call for the remaining brackets.

If open bracket count is less than n, then put an opening bracket and call printParenthesis()
for the remaining brackets.
