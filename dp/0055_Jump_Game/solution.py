'''
55. Jump Game

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

reference
    https://www.hrwhisper.me/leetcode-jump-game/
'''


class Solution(object):
    # neglect " maximum jump length "
    def canJump_error(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if not nums:
            return False
        i = 0
        while i < len(nums):
            if i >= len(nums) - 1:
                return True
            num = nums[i]
            if num == 0 and i < (len(nums) - 1):
                return False
            i += num
        return i >= len(nums)

    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if not nums:
            return False
        step = nums[0]
        for i in xrange(1, len(nums)):
            if step > 0:
                step -= 1
                step = max(step, nums[i])
            else:
                return False
        return True

    # cover is the max index can jump to
    def canJump_2(self, nums):
        cover = 0
        for i in xrange(len(nums)):
            if cover >= len(nums) - 1:
                return True
            if cover >= i:
                cover = max(cover, nums[i] + i)
        return False


# input = [0, 1]
s = Solution()

# input = [2, 0, 0]
# print s.canJump(input)

input = [2, 5, 0, 0]
print s.canJump_2(input)
