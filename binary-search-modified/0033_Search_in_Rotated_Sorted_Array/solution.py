'''
33. Search in Rotated Sorted Array   [#81]

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Reference:
    Cracking the Coding Interview   Ch6 P32
    Cracking the Coding Interview   9.11-11.3 P256

'''


class Solution(object):
    def search_my(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if not nums:
            return -1
        left = 0
        right = len(nums) - 1
        while (left + 1 < right):
            mid = left + (right - left) / 2
            if nums[mid] == target:
                return mid
            if nums[mid] > nums[left]:  # the element in left half goes in increasing order
                if nums[left] <= target and target <= nums[mid]:  # target between left and mid, use <= here
                    right = mid
                else:
                    left = mid
            else:  # the reset is in left half, the element in right half goes in increasing order
                if nums[mid] <= target and target <= nums[right]:
                    # target in right half
                    left = mid
                else:
                    right = mid

        if nums[left] == target:
            return left
        if nums[right] == target:
            return right
        return -1

    # The elements in the list goes in increasing order, then drop down, and increase again.
    # The minimum element is the reset point
    # if mid > right, the reset point will be in right half
    # if mid < right, the reset point will be in left half
    def search_bs(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left, right = 0, len(nums) - 1
        while left <= right:
            if nums[left] == target:
                return left
            if nums[right] == target:
                return right
            m = (left + right) / 2
            mid = nums[m]
            if mid == target:
                return m

            if mid > nums[left]:
                # the element in left half goes in increasing order
                if nums[left] < target and target < nums[m]:
                    # target in left half
                    right = m - 1
                else:
                    left = m + 1
            else:
                # the reset is in left half, the element in right half goes in increasing order
                if nums[m] < target and target < nums[right]:
                    # target in right half
                    left = m + 1
                else:
                    right = m - 1
        else:
            return -1


s = Solution()
print s.search_bs([4, 5, 6, 7, 0, 1, 2], 1)
print s.search_bs([1, 3], 3)
