'''
303. Range Sum Query - Immutable

Given an integer array nums, find the sum of the elements between indices i and j (i <= j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:
    You may assume that the array does not change.
    There are many calls to sumRange function.
'''


class NumArray(object):
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        self.nums = nums
        self.dic = {}
        sum = 0
        for i in xrange(len(nums)):
            sum += nums[i]
            self.dic[i] = sum

    # time limit exceeded
    def sumRange_naive(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """

        sum = 0
        for x in xrange(i, j + 1):
            sum += self.nums[x]

        return sum

    def sumRange_naive(self, i, j):
        if i == 0:
            return self.dic[j]
        return self.dic[j] - self.dic[i-1]   # dic[i-1] !
