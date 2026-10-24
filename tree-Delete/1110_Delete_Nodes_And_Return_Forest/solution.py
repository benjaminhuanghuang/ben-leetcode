'''
1110. Delete Nodes And Return Forest

Level: Medium

https://leetcode.com/problems/delete-nodes-and-return-forest
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
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        