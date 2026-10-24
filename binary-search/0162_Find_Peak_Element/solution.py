'''
162. Find Peak Element

A peak element is an element that is greater than its neighbors.

Given an input array where num[i] != num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = min_int.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
'''


class Solution(object):
    # O(logN)
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l, r = 0, len(nums) - 1

        while l < r:
            mid = l + (r - l) / 2

            if nums[mid] >= nums[mid + 1]:
                r = mid
            else:
                l = mid + 1

        return l

    # O(n)
    def findPeakElement_niave(self, nums):
        max = nums[0]
        index = 0
        for i in xrange(1, len(nums) - 1):
            prev = nums[i - 1]
            curr = nums[i]
            next = nums[i + 1]
            if curr > prev and curr > next:
                return i
            elif curr > max:
                max = curr

        if nums[-1] > max:
            index = len(nums) - 1
        return index


s = Solution()
print s.findPeakElement_niave([1, 2, 3, 1])
print s.findPeakElement_niave([1, 2])
