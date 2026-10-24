class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True

        return self.is_same_tree(root.left, root.right)

    def is_same_tree(self, left, right):
        if left is None and right is None:
            return True
        if not (left and right):
            return False

        return left.val == right.val and self.is_same_tree(left.left, right.right) and self.is_same_tree(left.right,
                                                                                                         right.left)
