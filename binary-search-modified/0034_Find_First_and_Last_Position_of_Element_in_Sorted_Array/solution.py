'''
34. Search for a Range

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].


'''


class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        left = 0
        right = len(nums) - 1

        result = [-1, -1]

        while left <= right:
            mid = (left + right) / 2

            if nums[mid] > target:
                right = mid - 1
            elif nums[mid] < target:
                left = mid + 1
            else:
                # nums[mid] == target
                result[0] = mid
                result[1] = mid

                i = mid - 1
                while i >= 0 and nums[i] == target:
                    result[0] = i
                    i -= 1

                i = mid + 1
                while i < len(nums) and nums[i] == target:
                    result[1] = i
                    i += 1

                break

        return result
