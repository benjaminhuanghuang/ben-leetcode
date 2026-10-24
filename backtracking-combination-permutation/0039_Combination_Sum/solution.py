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
