class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 2:
            return len(nums)

        slow = 1
        fast = 2
        while fast < len(nums):
            if nums[fast] == nums[slow] and nums[fast] == nums[slow - 1]:
                fast += 1
            else:
                slow += 1
                nums[slow] = nums[fast]
                fast += 1
        return slow + 1


s = Solution()
nums = [1, 1, 1, 2, 2, 3]

print s.removeDuplicates(nums)
print nums
