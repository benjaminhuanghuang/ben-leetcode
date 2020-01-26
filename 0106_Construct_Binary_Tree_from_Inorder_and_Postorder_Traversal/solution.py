'''
106. Construct Binary Tree from Inorder and Postorder Traversal

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
'''
from data_structure.tree_node import TreeNode


class Solution(object):
    #  Memory Limit Exceeded
    def buildTree_bad(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """

        if inorder:
            root_pos = inorder.index(postorder[-1])
            del postorder[-1]
            root = TreeNode(inorder[root_pos])
            root.left = self.buildTree(inorder[0: root_pos], postorder[:root_pos])
            root.right = self.buildTree(inorder[root_pos + 1: len(inorder)], postorder[root_pos:])

            return root

    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        self.postorder = postorder
        self.inorder = inorder
        return self._buildTree(0, len(inorder))

    def _buildTree(self, start, end):
        if start < end:
            root = TreeNode(self.postorder.pop())
            index = self.inorder.index(root.val)
            root.right = self._buildTree(index + 1, end)
            root.left = self._buildTree(start, index)
            return root


s = Solution()
tree = s.buildTree([2, 1, 3], [2, 3, 1])

print tree
