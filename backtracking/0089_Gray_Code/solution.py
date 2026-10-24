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
