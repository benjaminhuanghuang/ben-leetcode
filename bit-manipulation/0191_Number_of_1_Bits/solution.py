'''
191. Number of 1 Bits

Write a function that takes an unsigned integer and returns the number of '1' bits it has
(also known as the Hamming weight).

For example, the 32-bit integer '11' has binary representation 00000000000000000000000000001011,
so the function should return 3.

'''


class Solution_my(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        ret = 0
        while n > 0:
            b = n & 1
            if b:
                ret += 1
            n = n >> 1
        return ret


def hamming_weight(n):
    num = 0
    for i in range(32):
        num += n & 1
        n = n >> 1
    return num


def hamming_weight2(n):
    num = 0
    for i in range(32):
        if n & (1 << i) != 0:
            num += 1
    return num


print hamming_weight(9)
