'''
203. Remove Linked List Elements

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
'''
from utilities.data_generator import *


class Solution(object):
    # First version
    def removeElements_wrong(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        new_head = head
        while head:
            if head.val == val:
                new_head = head.next
            else:
                break
            head = head.next

        head = new_head

        if not head:
            return None

        curr = head
        # ! miss case [1] remove 1
        while curr and curr.next:
            if curr.next.val == val:
                curr.next = curr.next.next
                # for case [1,2,2,1] val =2
            else:
                curr = curr.next

        return head

    # Use a dummy head to simplify
    def removeElements(self, head, val):
        if not head:
            return head

        dummy = ListNode(0)
        dummy.next = head

        pre = dummy
        while head:
            if head.val == val:
                pre.next = head.next
                head = pre.next
            else:
                pre = head
                head = head.next
        return dummy.next

    # http://www.jiuzhang.com/solutions/remove-linked-list-elements/
    def removeElements_9(self, head, val):
        # Write your code here
        if head == None:
            return head
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy
        while head:
            if head.val == val:
                pre.next = head.next
                head = pre   # What is the purpose of this line?
            pre = head
            head = head.next
        return dummy.next


s = Solution()

# list_head = generate_list([1, 2, 6, 3, 4, 5, 6])
# print_list(list_head)

# list_head = s.removeElements_naive(list_head, 6)
# print_list(list_head)
#
# list_head = generate_list([1, 2, 6, 3, 4, 5, 6])
# list_head = s.removeElements(list_head, 6)
# print_list(list_head)
#
# list_head = generate_list([1, 2, 2, 1])
# list_head = s.removeElements(list_head, 2)
# print_list(list_head)

list_head = generate_list([1])
list_head = s.removeElements(list_head, 1)
print_list(list_head)
