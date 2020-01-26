'''
80. Remove Duplicates from Sorted Array II

ollow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
It doesn't matter what you leave beyond the new length.
'''


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
