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
