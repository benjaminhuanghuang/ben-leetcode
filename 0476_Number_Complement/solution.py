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
