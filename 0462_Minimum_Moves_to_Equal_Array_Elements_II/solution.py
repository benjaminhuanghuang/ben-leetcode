class Solution(object):
    def minMoves2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        nums.sort()
        mid = nums[(n-1)/2]
        res =0
        for i in nums:
            res += abs(i -mid)
        return res

