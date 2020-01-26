'''
476. Number Complement

Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary
representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer's binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need
to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
'''


class Solution(object):
    def findComplement_Wrong(self, num):
        return ~num + 1

    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """

        s = bin(num)[2:]
        S = []
        for i in range(len(s)):
            if s[i] == '1':
                S.append('0')
            else:
                S.append('1')

        return int("".join(S), base=2)


s = Solution()
print s.findComplement(5)
