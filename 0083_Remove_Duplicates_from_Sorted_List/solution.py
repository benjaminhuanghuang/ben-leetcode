'''
83. Remove Duplicates from Sorted List
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
'''


class Solution(object):
    def deleteDuplicates_my_not_prefect(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head
        prev = head
        curr = head.next
        while curr:
            if prev.val == curr.val:
                prev.next = curr.next
                curr.next = None
                curr = prev.next
            else:
                prev = prev.next
                curr = curr.next
        return head


def delete_duplicates_good(head):
    if head == None:
        return None

    current = head
    while current.next:
        next = current.next
        if next.val == current.val:
            current.next = current.next.next
        else:
            current = next
    return head
