class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """

        if root is None:
            return []
        return self.inorderTraversal(root.left) + [root.val] \
               + self.inorderTraversal(root.right)

    def inorderTraversal_2(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """

        if root is None:
            return []
        res = []
        stack = []
        self.pushLeftMost(root, stack)
        while stack:
            top = stack.pop()
            res.append(top.val)
            self.pushLeftMost(top.right, stack)
        return res

    def pushLeftMost(self, node, stack):
        while node:
            stack.append(node)
            node = node.left
