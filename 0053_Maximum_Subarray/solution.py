'''
53. Maximum Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6


Hints:
    nums[i] = max(nums[i - 1] + nums[i], nums[i])
'''


class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums is None or len(nums) == 0:
            return 0

        maxSum = nums[0]
        sum = 0
        for num in nums:
            if sum < 0:
                sum = num
            else:
                sum += num
            maxSum = max(maxSum, sum)
        return maxSum

    # Can not pass [-1]
    def maxSubArray_my(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums is None or len(nums) == 0:
            return 0

        maxSum = nums[0]
        sum = 0
        for num in nums:
            if num < 0:
                sum = 0    # Error!
            else:
                sum += num
            maxSum = max(maxSum, sum)
        return maxSum
        #
        # nums[i] = max(nums[i - 1] + nums[i], nums[i])
        #


def maxSubArray_2(self, nums):
    for i in xrange(1, len(nums)):
        nums[i] = max(nums[i - 1] + nums[i], nums[i])
    return max(nums)


s = Solution()
print s.maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4])
