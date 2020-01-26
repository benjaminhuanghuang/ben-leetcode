'''
224. Basic Calculator

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative
integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
'''


class Solution(object):
    # https://www.hrwhisper.me/leetcode-math/
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.strip()
        stack = []
        sign = 1
        n = len(s)
        ans = num = 0
        for i in xrange(n):
            if s[i] == ' ':
                continue
            if s[i].isdigit():
                # num = num * 10 + ord(s[i]) - 48
                num = num * 10 + int(s[i])
            if s[i] in ['+', '-', '(', ')'] or i == n - 1:
                if s[i] == '(':
                    stack.append(ans)
                    stack.append(sign)
                    ans = 0
                    sign = 1
                elif s[i] == ')':
                    ans += num * sign
                    sign = stack.pop()
                    num = stack.pop()
                    ans = num + ans * sign
                    sign = 1
                else:   # + , - or number
                    ans += num * sign
                    sign = 1 if s[i] == '+' else  -1
                num = 0
        return ans

    def calculate_2(self, s):
        res = 0
        signs = [1, 1]
        i = 0

        while i < len(s):
            char = s[i]
            if char.isdigit():
                start = i
                while i < len(s) and s[i].isdigit():
                    i += 1
                res += signs.pop() * int(s[start:i])
                continue
            elif char in '(+-':
                signs += signs[-1] * (1, -1)[char == '-'],
            elif char == ')':
                signs.pop()

            i += 1

        return res


input = "11 + 1"
input = " 2-1 + 2 "
# input = "(1+(4+5+2)-3)+(6+8)"
s = Solution()
print s.calculate_2(input)
