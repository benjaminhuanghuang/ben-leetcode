'''
137. Single Number II

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
'''


class Solution(object):

    # Time limit exceeded
    def singleNumber_niave(self, nums):
        resultDic = {}
        for i in nums:
            if i in resultDic.keys():
                if resultDic[i] == 2:
                    del resultDic[i]
                else:
                    resultDic[i] = resultDic[i] + 1
            else:
                resultDic[i] = 1
        return list(resultDic.keys())[0]

    # O(n) time O(1) space
    # Get the occurrence of '1' at each bit. If count % 3 == 0 means this bit of the result is 0.
    # If count % 3 == 1 means this bit of the result is 1.
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0

        for i in range(32):
            count = 0
            for j in nums:
                if j >> i & 1:
                    count += 1
            if count % 3 == 1:
                ans |= 1 << i

        if ans >= 2 ** 31:
            ans -= 2 ** 32
        return ans


    # http://suroot.cn/418.html
    def singleNumber_3(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        one, two, three = 0, 0, 0
        for v in nums:
            two |= one & v
            one ^= v
            three = ~(one & two)
            one &= three
            two &= three
        return one