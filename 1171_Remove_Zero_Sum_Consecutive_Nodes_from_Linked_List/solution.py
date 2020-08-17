'''
1171. Remove Zero Sum Consecutive Nodes from Linked List

Level: Medium

https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list
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
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        