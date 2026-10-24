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
