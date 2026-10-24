from data_structure.list_node import ListNode
from utilities.data_generator import *


class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head

        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        while head and head.next:
            if head.val == head.next.val:
                val = head.val
                while head and val == head.val:
                    head = head.next
                prev.next = head
            else:
                head = head.next
                prev = prev.next

        return dummy.next


list = generate_list([1, 1])

s = Solution()
print s.deleteDuplicates(list)
