'''
19. Remove Nth Node From End of List

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

'''
from data_structure.list_node import ListNode


class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        feak_head = ListNode(0)
        feak_head.next = head
        slow = feak_head
        fast = head
        for i in range(0, n):
            fast = fast.next

        while fast != None:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next
        return feak_head.next
