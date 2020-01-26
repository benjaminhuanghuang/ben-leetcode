'''
39. Combination Sum

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate
numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
  [7],
  [2, 2, 3]
]
'''


class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        self.result = []
        self.dfs(candidates, target, 0, [])
        return self.result

    def dfs(self, candidates, target, index, combination):
        length = len(candidates)
        if target == 0:
            return self.result.append(combination)

        for i in range(index, length):
            if target < candidates[i]:
                return
            self.dfs(candidates, target - candidates[i], i, combination + [candidates[i]])
