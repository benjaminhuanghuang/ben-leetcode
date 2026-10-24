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
