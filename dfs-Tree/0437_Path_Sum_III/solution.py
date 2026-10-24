class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        if not root:
            return 0
        return self.dfs(root, sum) + self.pathSum(root.left, sum) + self.pathSum(root.right, sum);

    def dfs(self, node, sum):
        res = 0
        if not node:
            return res
        if sum == node.val:
            res += 1
        res += self.dfs(node.left, sum - node.val)
        res += self.dfs(node.right, sum - node.val)

        return res
