'''
725. Split Linked List in Parts

Level: Medium

https://leetcode.com/problems/split-linked-list-in-parts
'''
'''
  Solution: 
'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, root: ListNode, k: int) -> List[ListNode]:
        