# http://bookshadow.com/weblog/2016/11/06/leetcode-minimum-moves-to-equal-array-elements/
class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(nums) - min(nums) * len(nums)