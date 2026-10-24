class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0

        return self.dfs(root, 0)

    def dfs(self, root, val):
        '''
        :param root:
        :param val:
        :return:
        '''
        # val is the value came from higher level

        val = val * 10 + root.val

        if (root.left or root.right) is None:
            return val

        sums = 0

        if root.left:
            sums += self.dfs(root.left, val)
        if root.right:
            sums += self.dfs(root.right, val)
        return sums
