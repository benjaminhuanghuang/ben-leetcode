'''
234. Palindrome Linked List

Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
'''


class Solution(object):
    # use extra space
    # time O(n), space O(n)
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head is None or head.next is None:
            return True

        vals = []
        while head:
            vals.append(head.val)
            head = head.next

        start = 0
        end = len(vals) - 1

        while start < end:
            if vals[start] != vals[end]:
                return False
            start += 1
            end -= 1
        return True

    # reverse list
    # time O(n), space O(1)
    def isPalindrome_2(self, head):
        if head is None or head.next is None:
            return True

        fast = head.next
        slow = head

        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next

        second_head = slow.next

        second_head = self.reverse_list(second_head)

        while head and second_head:
            if head.val != second_head.val:
                return False
            head = head.next
            second_head = second_head.next

        return True


    def reverse_list(self, head):
        if head is None or head.next is None:
            return head

        prev = None
        while head:
            next = head.next
            head.next = prev
            prev = head
            head = next
        return prev
