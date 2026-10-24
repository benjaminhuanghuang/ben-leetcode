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
