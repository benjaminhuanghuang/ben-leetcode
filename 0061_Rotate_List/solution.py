'''
61. Rotate List

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

'''
from data_structure.list_node import ListNode


class Solution(object):
    def rotateRight(self, head, k):
        if k == 0 or head is None:
            return head
        tail = head
        count = 1
        while tail.next:
            tail = tail.next
            count += 1
        # make a cycle
        tail.next = head
        step = count - (k % count)
        for i in xrange(step):
            tail = tail.next
        new_head = tail.next
        tail.next = None
        return new_head





