# http://blog.csdn.net/nomasp/article/details/50572933
class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0

        if root.left and root.right:
            return min(self.minDepth(root.left), self.minDepth(root.right)) + 1
        elif root.left:
            return self.minDepth(root.left) + 1
        else:
            return self.minDepth(root.right) + 1
