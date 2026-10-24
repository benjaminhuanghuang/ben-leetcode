'''
287. Find the Duplicate Number

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
'''


class Solution(object):
    #  time : O(NlogN)
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l, r = 1, len(nums) - 1
        while l <= r:
            mid = (l + r) >> 1
            # the count of the nums <= mid
            cnt = sum([1 for num in nums if num <= mid])

            if cnt <= mid:
                l = mid + 1
            else:
                r = mid - 1
        return l

    def count(self, nums, mid):
        c = 0
        for i in xrange(len(nums)):
            if nums[i] <= mid:
                c += 1
        return c

    # time O(N)
    # https://www.hrwhisper.me/leetcode-find-the-duplicate-number/
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        slow, fast = nums[0], nums[nums[0]]
        while slow != fast:
            slow = nums[slow]
            fast = nums[nums[fast]]

        slow = 0
        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]
        return slow
