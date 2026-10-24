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
