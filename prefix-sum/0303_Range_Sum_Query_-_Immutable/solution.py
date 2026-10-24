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
