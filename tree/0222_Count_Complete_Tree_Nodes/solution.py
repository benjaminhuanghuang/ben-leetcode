'''
222. Count Complete Tree Nodes

Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last
level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
'''


class Solution(object):
    # Time limit Exceeded, recursive O(N)
    def countNodes_my(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        if root is None:
            return 0
        count = 1
        if root.left:
            count += self.countNodes(root.left)
        if root.right:
            count += self.countNodes(root.right)

        return count

    # Complete bin tree means only the last level is not full.
    # If the complete bin tree is full, node count = 2 ^ h = 1 << level
    # http://www.tangjikai.com/algorithms/leetcode-222-complete-tree-nodes
    # http://blog.neoshell.moe/leetcode222.html
    #
    #  O(logn ^ 2) time
    def countNodes_bs(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        if root is None:
            return 0

        depth = 0
        n = root
        while n:
            depth += 1
            n = n.left

        if depth == 1:
            return 1

        num = 1 << (depth - 1)

        # binary search (find upper bound)
        l, r = 0, num - 1
        if self.getDepth(root, r, num) == depth:
            return num * 2 - 1

        while l < r:
            mid = l + (r - l) / 2
            if self.getDepth(root, mid, num) == depth:
                l = mid + 1
            else:
                r = mid

        return (num - 1) + l

    def getDepth(self, root, id, num):
        depth = 0

        while root:
            depth += 1
            num /= 2

            if id >= num:
                root = root.right
                id -= num
            else:
                root = root.left

        return depth

    def countNodes_recursive(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        if root is None:
            return 0
        left_hight = self.get_height(root, True)
        right_hight = self.get_height(root, False)

        if left_hight == right_hight:
            return (1 << left_hight) - 1
        else:
            return self.countNodes(root.left) + self.countNodes(root.right) + 1

    def get_height(self, root, left):
        h = 0
        while root:
            if left:
                root = root.left
            else:
                root = root.right
            h += 1
        return h
