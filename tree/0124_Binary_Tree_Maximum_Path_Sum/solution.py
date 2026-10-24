'''
124. Binary Tree Maximum Path Sum  [Hard]

Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree
along the parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
'''
from sys import maxint

class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.maxSum = -maxint-1
        self.maxPathSum_helper(root)
        return self.maxSum

    # 1. return max of left branch or right branch
    # 2. cal maxSum
    def maxPathSum_helper(self, root):
        if root is None:
            return 0
        left = self.maxPathSum_helper(root.left)
        right = self.maxPathSum_helper(root.right)
        left = left if left > 0 else 0
        right = right if right > 0 else 0
        self.maxSum = max(self.maxSum, root.val + left + right)
        return max(left, right) + root.val
