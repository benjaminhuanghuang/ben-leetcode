'''
190. Reverse Bits

Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100),
return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

'''


class Solution(object):
    def reverseBits(self, n):
        """
        :type n: int
        :rtype: int
        """
        table = []
        result = 0
        for i in range(32)[::-1]:
            table.append(2 ** i)

        for j in range(32):
            if n & 1:
                result += table[j]
            n = n >> 1
        return result

    # Good!
    def reverseBits_2(self, n):
        """
        :type n: int
        :rtype: int
        """
        res = 0
        for i in xrange(32):
            res = (res << 1) + (n >> i & 1)
        return res

    def reverseBits_wrong(self, n):
        res = 0
        while n > 0:  # only get one bit
            b = n & 1
            res = (res << 1) + b
            n = n >> 1
        return res
