'''
558. Logical OR of Two Binary Grids Represented as Quad-Trees

Level: Medium

https://leetcode.com/problems/logical-or-of-two-binary-grids-represented-as-quad-trees
'''
'''
  Solution: 
'''
"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def intersect(self, quadTree1: 'Node', quadTree2: 'Node') -> 'Node':
        