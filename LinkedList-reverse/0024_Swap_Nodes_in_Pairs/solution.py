'''
24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

'''

from data_structure.list_node import ListNode

# Wrong answer, infinite loop
def swap_nodes_in_pairs_wrong(head):
    if head is None:
        return None
    new_head = ListNode(0)
    tail = new_head

    while head and head.next:
        tail.next = head.next
        tail.next.next = head
        # head.next.next is head!!!
        tail = tail.next.next
        head = head.next.next

    if head:
        tail.next = head

    return new_head.next


def swap_nodes_in_pairs(head):
    if head is None:
        return None
    new_head = ListNode(0)
    tail = new_head

    while head and head.next:
        next_start = head.next.next

        tail.next = head.next
        tail.next.next = head
        head.next = next_start

        tail = tail.next.next
        head = head.next

    if head:
        tail.next = head

    return new_head.next

class Solution_my(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return
        feakhead = ListNode(-1)

        prev = feakhead
        prev.next = head
        while head and head.next:
            next = head.next.next
            prev.next = head.next
            prev.next.next = head
            head.next = next

            prev = prev.next.next
            head = prev.next


        return feakhead.next

head = ListNode(1)
curr_node = head
curr_node.next = ListNode(2)
curr_node = curr_node.next
curr_node.next = ListNode(3)
curr_node = curr_node.next
curr_node.next = ListNode(4)

new_head = swap_nodes_in_pairs(head)

while new_head:
    print new_head.val
    new_head = new_head.next
