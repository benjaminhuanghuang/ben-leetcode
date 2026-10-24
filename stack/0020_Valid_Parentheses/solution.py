'''
20. Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
'''


class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        for i in range(len(s)):
            if s[i] == '(' or s[i] == '[' or s[i] == '{':
                stack.append(s[i])
            if s[i] == ')':
                if len(stack) == 0 or stack.pop() != '(':
                    return False
            if s[i] == ']':
                if len(stack) == 0 or stack.pop() != '[':
                    return False
            if s[i] == '}':
                if len(stack) == 0 or stack.pop() != '{':
                    return False
        if stack:
            return False
        else:
            return True

    def isValid_my(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        for char in s:
            if char == '(' or char == '{' or char == '[':
                stack.append(char)
            if char == ')':
                if stack and stack[-1] == '(':
                    stack.pop()
                else:
                    return False
            if char == ']':
                if stack and stack[-1] == '[':
                    stack.pop()
                else:
                    return False
            if char == '}':
                if stack and stack[-1] == '{':
                    stack.pop()
                else:
                    return False
        if len(stack) == 0:
            return True
        return False
