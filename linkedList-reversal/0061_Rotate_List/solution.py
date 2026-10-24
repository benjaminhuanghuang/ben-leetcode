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





