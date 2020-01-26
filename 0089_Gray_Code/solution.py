'''
89. Gray Code

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code.
A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

'''


class Solution(object):
    '''
    n = 0 result = [0]
    n = 1 result = [0, 1]
    n = 2 result = [00, 01, 11, 10]      11 = 01 + 1<<1  10 = 00 + 1<<1
    '''

    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """

        result = [0]
        for i in range(n):
            l = []
            for num in result:
                # Note!  : num + 1 << i is not correct
                l.append(num + (1 << i))
            result += l[::-1]
        return result


s = Solution()
print s.grayCode(2)

print 1 + 1 << 1
