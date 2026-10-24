class Solution(object):
    # Remove elements equals to val and return the new length
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """

        pivot = len(nums) - 1
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] == val:
                nums[i], nums[pivot] = nums[pivot], nums[i]
                pivot -= 1
        return pivot + 1   # pivot is index, return value should be length
