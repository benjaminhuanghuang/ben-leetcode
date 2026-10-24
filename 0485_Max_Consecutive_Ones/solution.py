class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_len = 0
        len = 0
        for n in nums:
            if n == 1:
                len += 1
            else:
                max_len = max(len, max_len)
                len = 0
        max_len = max(len, max_len)
        return max_len


input[1, 1, 0, 1, 1, 1]
