'''
78. Subsets

Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

'''


class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if nums is None or len(nums) == 0:
            return [[]]
        # nums.sort()

        result = []
        combination = []
        self.helper(result, combination, nums, 0)
        return result

    def helper(self, result, combination, nums, pos):
        result.append(list(combination))  # append a copy of line to result

        for i in range(pos, len(nums)):
            combination.append(nums[i])
            self.helper(result, combination, nums, i + 1)
            combination.pop()

    def subsets_2(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # nums.sort()

        result = []
        line = []
        self.helper(nums, result, line)
        return result

    def helper(self, nums, result, line):
        result.append(list(line))  # append a copy of line to result

        for i, x in enumerate(nums):
            # in this loop, line + nums[i]...line + nums[n]
            line.append(x)
            self.helper(nums[i + 1:], result, line)
            line.pop()


s = Solution()
print s.subsets_2([1, 2, 3])
