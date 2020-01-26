'''
26. Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.

reference:
https://github.com/zhouchong90/LeetCode-Python-Solution/

'''


class Solution(object):
    # sample:  1111111234
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if nums is None:
            return 0
        if length < 2:
            return length
        size = 0
        for i in xrange(1, length):
            if nums[i] != nums[size]:
                size += 1
                nums[size] = nums[i]
        return size + 1


nums = [1, 1, 1, 1, 2, 3, 3, 4, 5]
nums = [1, 2]

s = Solution()
print s.removeDuplicates(nums)
print nums
