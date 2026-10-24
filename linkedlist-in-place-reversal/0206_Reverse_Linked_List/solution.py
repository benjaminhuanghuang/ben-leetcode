'''
206. Reverse Linked List

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
'''

class Solution(object):
    def reverseList_iteratively(head):
        prev = None
        current = head
        while current:
            next = current.next
            current.next = prev
            prev = current
            current = next
        return prev

    def reverseList_recursively(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head
        if not head.next:
            return head

        rest = self.reverseList_recursively(head.next)
        # head.next the tail node in the rest part
        head.next.next = head
        head.next = None

        return rest