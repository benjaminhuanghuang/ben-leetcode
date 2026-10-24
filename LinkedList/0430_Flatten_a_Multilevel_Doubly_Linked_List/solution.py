'''
430. Flatten a Multilevel Doubly Linked List

Level: Medium

https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list
'''
'''
  Solution: 
'''
"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        