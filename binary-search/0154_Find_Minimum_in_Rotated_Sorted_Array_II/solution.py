'''
154. Find Minimum in Rotated Sorted Array II

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.

reference:
    http://bangbingsyb.blogspot.com/2014/11/leecode-find-minimum-in-rotated-sorted.html
'''


class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        low = 0
        high = len(nums) - 1
        while (low < high):
            if(nums[low] < nums[high]):
                return nums[low]
            mid = low + (high - low) / 2
            if nums[mid] < nums[high]:
                high = mid
            elif (nums[mid] > nums[low]):
                low = mid + 1
            else:
                low += 1
        return nums[low]


nums = [1, 1, 3]

s = Solution()
print s.findMin(nums)
