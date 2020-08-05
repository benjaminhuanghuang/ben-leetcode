'''
1315. Sum of Nodes with Even-Valued Grandparent

Level: Medium

https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent
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
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        