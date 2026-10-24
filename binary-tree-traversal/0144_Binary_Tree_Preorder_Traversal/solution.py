'''
144. Binary Tree Preorder Traversal
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
'''


class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root is None:
            return []
        return [root.val] + self.preorderTraversal(root.left) + self.preorderTraversal(root.right)

    def preorderTraversal_Iterative(self, root):
        res = []
        stack = []
        if root:
            stack.append(root)
        while stack:
            top = stack.pop()
            res.append(top.val)

            # note: push right firstly.
            if top.right:
                stack.append(top.right)
            if top.left:
                stack.append(top.left)
        return res


