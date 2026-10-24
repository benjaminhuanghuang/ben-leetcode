'''
47. Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

'''


class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if nums is None:
            return []

        if len(nums) == 0:
            return [[]]

        result = []
        self.permute(result, [], sorted(nums))
        return result

    def permute(self, result, temp, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if nums == []:
            result += [temp]
        else:
            for i in range(len(nums)):
                if i > 0 and nums[i] == nums[i - 1]:
                    continue
                self.permute(result, temp + [nums[i]], nums[:i] + nums[i + 1:])


input = [1, 1, 2]
s = Solution()
print s.permuteUnique(input)
