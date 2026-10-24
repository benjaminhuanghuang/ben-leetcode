class Solution(object):
    # https://www.hrwhisper.me/leetcode-longest-valid-parentheses/
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        match = [0 for i in range(0, len(s))]
        for i, c in enumerate(s):
            if c == '(':
                stack.append(i)
            elif c == ')' and len(stack) != 0:
                match[i] = match[stack[-1]] = 1   # current ) and last (
                stack.pop()

        ans, temp = 0, 0
        for i, c in enumerate(match):
            if match[i]:
                temp = temp + 1
                ans = max(ans, temp)
            else:
                temp = 0
        return ans


input = ")(((((()())()()))()(()))("
# input = ")(((((((()()))))))))))))))))))))))))))))))))))))))))))))))()))()(()))("
s = Solution()
print s.longestValidParentheses(input)
