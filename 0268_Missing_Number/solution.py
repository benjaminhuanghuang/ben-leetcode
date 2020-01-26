'''
268. Missing Number

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing
from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant
extra space complexity?
'''


class Solution(object):
    def missingNumber_naive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in xrange(1, len(nums)):
            diff = nums[i] - nums[i - 1]
            if diff > 2:
                return nums[i] - 1
        return -1

    def missingNumber_1(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        n = len(nums)

        return n * (n + 1) / 2 - sum(nums)
