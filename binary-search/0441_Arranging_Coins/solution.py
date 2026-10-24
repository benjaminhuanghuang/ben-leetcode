import math


class Solution(object):
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        '''
            (1+k)*k/2 = n
            k+k*k = 2*n
            k*k + k + 0.25 = 2*n + 0.25
            (k + 0.5) ^ 2 = 2*n +0.25
            k + 0.5 = sqrt(2*n + 0.25)
            k = sqrt(2*n + 0.25) - 0.5
        '''
        return int(math.sqrt(2 * n + 0.25) - 0.5)
