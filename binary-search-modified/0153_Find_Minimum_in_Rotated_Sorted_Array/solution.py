'''
153. Find Minimum in Rotated Sorted Array

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
'''


class Solution(object):
    def findMin(self, nums):
        low = 0
        high = len(nums) - 1
        while (low < high):
            if (nums[low] < nums[high]):
                return nums[low]
            mid = low + (high - low) / 2
            if nums[mid] < nums[high]:
                high = mid
            else:
                low = mid + 1
        return nums[low]
