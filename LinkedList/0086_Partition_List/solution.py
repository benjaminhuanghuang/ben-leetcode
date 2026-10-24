from data_structure.list_node import ListNode


class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        head_smaller = ListNode(0)
        head_bigger = ListNode(0)
        p_smaller = head_smaller
        p_bigger = head_bigger

        current = head
        while current:
            if current.val < x:
                p_smaller.next = current
                current = current.next
                p_smaller = p_smaller.next
                p_smaller.next = None
            else:
                p_bigger.next = current
                current = current.next
                p_bigger = p_bigger.next
                p_bigger.next = None

        p_smaller.next = head_bigger.next
        return head_smaller.next
