'''
129. Sum Root to Leaf Numbers

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
'''


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
