from data_structure.tree_node import TreeNode


class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n == 0:
            return []

        return self.dfs(1, n)

    def dfs(self, start, end):
        if start > end:
            return [None]
        res = []
        for rootval in range(start, end + 1):
            LeftTrees = self.dfs(start, rootval - 1)
            RightTrees = self.dfs(rootval + 1, end)
            for ltree in LeftTrees:
                for rtree in RightTrees:
                    root = TreeNode(rootval)
                    root.left = ltree
                    root.right = rtree
                    res.append(root)
        return res


s = Solution()
res = s.generateTrees(3)
print res
