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
