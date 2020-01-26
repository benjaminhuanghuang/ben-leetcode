'''
16. 3Sum Closest

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

'''


class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        result = None
        for i in range(len(nums)):
            l, r = i + 1, len(nums) - 1
            while (l < r):
                sum = nums[l] + nums[r] + nums[i]
                if result is None or abs(sum - target) < abs(result - target):
                    result = sum
                if sum <= target:
                    l = l + 1
                else:
                    r = r - 1
        return result

nums = [-1,2,1,-4]
target =1
s = Solution()
print s.threeSumClosest(nums, target)