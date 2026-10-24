class Solution(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return "0"

        is_negative = False
        if num < 0:
            num = -num
            is_negative = True

        res = ''
        while num > 0:
            res = str(num % 7) + res
            num = num / 7

        if is_negative:
            res = '-' + res

        return res

    def convertTo7_better(self, num):
        """
        :type num: int
        :rtype: str
        """
        n = abs(num)
        ans = ''
        while n:
            ans += str(n % 7)
            n /= 7
        return ['', '-'][num < 0] + ans[::-1] or '0'


s = Solution()
print s.convertToBase7(100)
