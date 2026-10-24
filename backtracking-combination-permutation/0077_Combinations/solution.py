'''
77. Combinations

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

Hints:
http://www.tianmaying.com/tutorial/LC77
'''


class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        res = []
        self.rec(res, 0, n, k, [])
        return res

    def rec(self, res, i, n, k, combination):
        if k == 0:
            res.append(combination)
            return
        for j in range(i + 1, n + 1):
            # temp.append(j)
            self.rec(res, j, n, k - 1, combination + [j])

    def combine_9(self, n, k):
        # write your code here
        self.res = []
        tmp = []
        self.dfs(n, k, 1, 0, tmp)
        return self.res

    def dfs(self, n, k, m, p, tmp):
        if k == p:
            self.res.append(tmp[:])
            return
        for i in range(m, n + 1):
            tmp.append(i)
            self.dfs(n, k, i + 1, p + 1, tmp)
            tmp.pop()

    # https://shenjie1993.gitbooks.io/leetcode-python/content/077%20Combinations.html
    # to n, have two choice: pick up (k-1) from 1 to (n-1) or pickup k from 1 to n-1
    def combine_fastest(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        if k == 1:
            return [[i + 1] for i in range(n)]

        result = []
        if n > k:
            result = [r + [n] for r in self.combine(n - 1, k - 1)] + self.combine(n - 1, k)
        else:
            result = [r + [n] for r in self.combine(n - 1, k - 1)]
        return result
