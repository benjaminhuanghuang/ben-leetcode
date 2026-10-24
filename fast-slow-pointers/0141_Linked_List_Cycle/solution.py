'''
141. Linked List Cycle

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

'''

from data_structure.list_node import ListNode


class Solution_my(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head:
            return False
        fast = head.next
        slow = head

        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                break
        # return fast != None   # Wrong!
        return fast != None and (fast.next != None)


# Solution 1
# O(n) space
def hasCycle_On(head):
    map = {}
    while head:
        if id(head) in map:
            return True
        else:
            map[id(head)] = True
        head = head.next
    return False


# O(1) space
#  Time Limit Exceeded
def has_cycle_O1(head):
    if head is None:
        return False

    fast_point = head
    slow_point = head

    while fast_point and slow_point and fast_point.next:
        fast_point = fast_point.next.next
        slow_point = slow_point.next
        if fast_point == slow_point:
            break

    return (fast_point != None) and (fast_point.next != None)


# solution 2  reverse cycle linked list will have same head
def hasCycle(head):
    if head and head.next and head == reverseList(head):
        return True
    return False


def reverseList(head):
    before = after = None
    while head:
        after = head.next
        head.next = before
        before = head
        head = after
    return before


list_node = ListNode(0)

print has_cycle_O1(list_node)
