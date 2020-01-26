'''
643. Maximum Average Subarray I
    # 53 Maximum Subarray
    # 533 Continuous Subarray Sum

Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].

'''


class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        sum_k_nums = sum(nums[:k])
        max_sum_k_nums = sum_k_nums
        for i in xrange(1, len(nums) - k + 1):
            sum_k_nums = sum_k_nums - nums[i - 1] + nums[i + k - 1]
            max_sum_k_nums = max(max_sum_k_nums, sum_k_nums)

        return float(max_sum_k_nums) / k


input = [1, 12, -5, -6, 50, 3]

#input = [0, 1, 1, 3, 3]

k = 4

solu = Solution()
print solu.findMaxAverage(input, k)
