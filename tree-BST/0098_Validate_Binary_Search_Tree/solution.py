MAX = (1 << 31)
MIN = - (1 << 31) - 1


class Solution_my(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.check(root, MIN, MAX)

    def check(self, root, min, max):
        if not root:
            return True

        if root.val <= min or root.val >= max:
            return False

        return self.check(root.left, min, root.val) and self.check(root.right, root.val, max)


class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        self.lastVal = None
        self.isBST = True
        self.validate(root)
        return self.isBST

    def validate(self, root):
        if root is None:
            return
        self.validate(root.left)
        if self.lastVal is not None and self.lastVal >= root.val:
            self.isBST = False
            return
        self.lastVal = root.val
        self.validate(root.right)
