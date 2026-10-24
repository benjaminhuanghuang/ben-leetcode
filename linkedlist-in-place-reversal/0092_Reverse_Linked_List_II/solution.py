'''
92. Reverse Linked List II

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 <= m <= n <= length of list.
'''

from data_structure.list_node import ListNode
from utilities.data_generator import *


class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        if head == None or head.next == None:
            return head

        dummy = ListNode(0)
        dummy.next = head
        head1 = dummy
        for i in range(m - 1):
            head1 = head1.next

        p = head1.next
        for i in range(n - m):
            tmp = head1.next
            head1.next = p.next
            p.next = p.next.next
            head1.next.next = tmp

        return dummy.next

    # revert node M to node N, node previous M and node post N need be keep
    def reverseBetween_9(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        if head == None or head.next == None:
            return head

        dummy = ListNode(0)
        dummy.next = head
        head = dummy
        for i in range(1, m):   # get previous N
            head = head.next

        # revert node N to node M, node previous N and node post M need be keep
        pre_m_node = head
        m_node = head.next
        n_node = m_node
        post_n_node = m_node.next


        for i in range(n-m):
            tmp = post_n_node.next
            post_n_node.next = n_node
            n_node = post_n_node
            post_n_node = tmp

        m_node.next = post_n_node
        pre_m_node.next = n_node

        return dummy.next


head = generate_list([3, 5])

s = Solution()
res = s.reverseBetween_9(head, 1, 2)
while res:
    print res.val
    res = res.next
