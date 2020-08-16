'''
1080. Insufficient Nodes in Root to Leaf Paths

Level: Medium

https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths
'''
'''
  Solution: 
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sufficientSubset(self, root: TreeNode, limit: int) -> TreeNode:
        