'''
105. Construct Binary Tree from Preorder and Inorder Traversal

Given preorder and inorder traversal of a tree, construct the binary tree.
'''
from data_structure.tree_node import TreeNode


class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        # write your code here
        if inorder:
            root_pos = inorder.index(preorder[0])
            del preorder[0]
            root = TreeNode(inorder[root_pos])
            root.left = self.buildTree(preorder, inorder[:root_pos])
            root.right = self.buildTree(preorder, inorder[root_pos + 1:])
            return root
