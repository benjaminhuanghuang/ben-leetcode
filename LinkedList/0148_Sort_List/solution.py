'''
148. Sort List

Sort a linked list in O(n log n) time using constant space complexity.

'''
from data_structure.list_node import ListNode


class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head

        slow = head
        fast = head.next

        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

        right = self.sortList(slow.next)

        slow.next = None
        left = self.sortList(head)

        return self.merge(left, right)

    def merge(self, l1, l2):
        dummy = cur = ListNode(0)

        while l1 and l2:
            if l1.val <= l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next

        cur.next = l1 or l2
        return dummy.next
