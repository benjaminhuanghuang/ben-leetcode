class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        prev_str = '1'

        for i in xrange(n - 1):
            tmp = ''
            count = 1
            for j in xrange(1, len(prev_str) + 1):
                if j < len(prev_str) and prev_str[j] == prev_str[j - 1]:
                    count += 1
                else:
                    tmp += str(count) + prev_str[j - 1]
                    count = 1
            prev_str = tmp

        return prev_str


s = Solution()
print s.countAndSay(7)
