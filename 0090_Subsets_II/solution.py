'''
90. Subsets II

Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

'''


class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        p = [[nums[x] for x in range(len(nums)) if i >> x & 1] for i in range(2 ** len(nums))]
        func = lambda x, y: x if y in x else x + [y]
        p = reduce(func, [[], ] + p)
        # return list(reversed(p))
        return p

    def subsetsWithDup(self, nums):
        def dfs(depth, start, valuelist):
            if valuelist not in res:
                res.append(valuelist)
            if depth == len(nums):
                return
            for i in range(start, len(nums)):
                dfs(depth + 1, i + 1, valuelist + [nums[i]])

        nums.sort()
        res = []
        dfs(0, 0, [])
        return res

    def subsetsWithDup_9(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        result = []
        self.helper(result, [], nums, 0)
        return result

    def helper(self, result, l, nums, pos):
        result.append(list(l))
        for i in xrange(pos, len(nums)):
            if i != pos and nums[i] == nums[i - 1]:
                continue
            l.append(nums[i])
            self.helper(result, l, nums, i + 1)
            l.pop()


s = Solution()

# print s.subsetsWithDup([1, 2, 2, 2])

print s.subsetsWithDup_9([1, 2, 2])
