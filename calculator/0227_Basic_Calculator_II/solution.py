class Solution(object):
    # https://www.hrwhisper.me/leetcode-math/
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        left = right = num = 0
        operator = '+'

        for i in xrange(n):
            if s[i] == ' ' and i < n - 1:
                continue
            if '0' <= s[i] <= '9':
                num = num * 10 + ord(s[i]) - 48
            if s[i] in ['+', '-', '*', '/'] or i == n - 1:
                if operator == '+':
                    left, right = left + right, num
                elif operator == '-':
                    left, right = left + right, -num
                elif operator == '*':
                    right *= num
                else:
                    right = right / num if right >= 0 else -(-right / num)  # -3 /2 in python is -2
                num = 0
                operator = s[i]
        return left + right

s = Solution()

res = s.calculate("5*3")

print res