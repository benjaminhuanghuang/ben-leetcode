'''
94. Binary Tree Inorder Traversal

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].


# 144, #145 #173

'''


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
