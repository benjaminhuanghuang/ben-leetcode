'''
38. Count and Say

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
'''


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
