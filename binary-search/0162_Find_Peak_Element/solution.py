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
