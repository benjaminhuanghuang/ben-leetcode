'''
75. Sort Colors

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent,
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

'''


class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if not nums or len(nums) < 2:
            return

        start = 0
        end = len(nums) - 1
        i = 0

        # Note: Wrong solution when use i < len(nums) -1
        while i <= end:
            if nums[i] == 2:
                nums[i], nums[end] = nums[end], nums[i]
                end -= 1
            elif nums[i] == 0:
                nums[i], nums[start] = nums[start], nums[i]
                start += 1
                i += 1
            else:
                i += 1

        return nums


s = Solution()

print s.sortColors([1, 2])
