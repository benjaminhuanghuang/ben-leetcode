class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        result = []
        self.DFS(result, candidates, target, 0, [])
        return result

    def DFS(self, result, candidates, target, start, valuelist):
        length = len(candidates)

        # if target == 0 and valuelist not in result:  # [1,7], [1,7]
        if target == 0:
            return result.append(valuelist)
        for i in range(start, length):
            if target < candidates[i]:
                return
            if candidates[i] == candidates[i-1] and i > start:
                continue
            self.DFS(result, candidates, target - candidates[i], i + 1, valuelist + [candidates[i]])


input = [10, 1, 2, 7, 6, 1, 5]
s = Solution()
print s.combinationSum2(input, 8)

print [1, 7] == [1, 7]
