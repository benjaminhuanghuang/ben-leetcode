'''
1145. Binary Tree Coloring Game

Level: Medium

https://leetcode.com/problems/binary-tree-coloring-game
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
    def btreeGameWinningMove(self, root: TreeNode, n: int, x: int) -> bool:
        