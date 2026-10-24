'''
25. Reverse Nodes in k-Group  [linked-list]

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
'''


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head == None:
            return None
        dummy_head = ListNode(0)
        dummy_head.next = head
        start = dummy_head
        while start.next:
            end = start
            for i in range(k - 1):
                end = end.next
                if end.next == None:
                    return dummy_head.next
            res = self.reverse(start.next, end.next)
            start.next = res[0]
            start = res[1]
        return dummy_head.next

    def reverse(self, start, end):
        newhead = ListNode(0)
        newhead.next = start
        while newhead.next != end:
            tmp = start.next
            start.next = tmp.next
            tmp.next = newhead.next
            newhead.next = tmp
        return [end, start]
