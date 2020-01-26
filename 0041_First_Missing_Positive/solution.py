'''
41. First Missing Positive

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
'''


class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        for i in range(n):
            if nums[i] <= 0:
                nums[i] = n + 2

        for i in range(n):
            if abs(nums[i]) <= n:
                curr = abs(nums[i]) - 1
                nums[curr] = -abs(nums[curr])
        for i in range(n):
            if nums[i] > 0:
                return i + 1
        return n + 1

    def firstMissingPositive_2(self, nums):
        if len(nums) == 0:
            return 1
        i = 0
        while i < len(nums):
            # put n to nums[i]
            if nums[i] > 0 and nums[i] < len(nums) and nums[nums[i]] != nums[i]:
                nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
            else:
                i = i + 1

        for x in xrange(1, len(nums)):
            if nums[x] != x:
                return x
        else:
            if nums[0] == len(nums):
                return len(nums) + 1
            else:
                return len(nums)

    # put x to nums[x-1]
    def firstMissingPositive_3(self, nums):
        i, n = 0, len(nums)
        while i < n:
            if nums[i] > 0 and nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
                # nums[i], nums[nums[i] - 1] = nums[nums[i] - 1], nums[i]  # error! infinite loop !!!
            else:
                i += 1

        for i in range(0, n):
            if nums[i] != i + 1:
                return i + 1
        return n + 1


s = Solution()
print s.firstMissingPositive_3([3, 4, -1, 1])
