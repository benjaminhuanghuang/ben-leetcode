'''
21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the
nodes of the first two lists.
'''
from data_structure.list_node import ListNode


# good version:
# 1. use a dummy to simplify
# 2. Do not handle v1 == v2.
def mergeTwoLists(l1, l2):
    dummy_head = ListNode(0)
    tail = dummy_head
    while l1 and l2:
        if l1.val < l2.val:
            tail.next = l1
            l1 = l1.next
        else:
            tail.next = l2
            l2 = l2.next
        tail = tail.next

    if l1:
        tail.next = l1
    else:
        tail.next = l2
    return dummy_head.next


def merge_sorted_lists(head1, head2):
    if head1 is None or head2 is None:
        return head1 or head2

    curr_node = None
    new_head = None
    while head1 and head2:
        if head1.val < head2.val:
            new_head, curr_node = append_node(new_head, curr_node, head1)
            head1 = head1.next
        elif head1.val > head2.val:
            new_head, curr_node = append_node(new_head, curr_node, head2)
            head2 = head2.next
        else:
            new_head, curr_node = append_node(new_head, curr_node, head1)
            head1 = head1.next
            new_head, curr_node = append_node(new_head, curr_node, head2)
            head2 = head2.next

    if head1:
        append_node(new_head, curr_node, head1)
    if head2:
        append_node(new_head, curr_node, head2)

    return new_head


def append_node(head, tail, node):
    if head is None:
        head = node

    if tail is None:
        tail = node
    else:
        tail.next = node

    return head, node


# -----------------------------------------------------
# Wrong answer :-(
# This solution for merge sorted array.
# -----------------------------------------------------
def merge_sorted_lists_wrong(l1, l2):
    if l1 is None or l2 is None:
        return l1 or l2

    new_list = []
    comm_length = min(len(l1), len(l2))
    i1 = 0
    i2 = 0
    while i1 < comm_length and i2 < comm_length:
        v1 = l1[i1]
        v2 = l2[i2]
        if v1 < v2:
            new_list.append(v1)
            i1 += 1
        elif v1 > v2:
            new_list.append(v2)
            i2 += 1
        else:
            new_list.append(v1)
            new_list.append(v2)
            i1 += 1
            i2 += 1
    if (len(l1) > comm_length):
        new_list += l1[comm_length:]
    if (len(l2) > comm_length):
        new_list += l2[comm_length:]

    return new_list


node1 = ListNode(1)
node2 = ListNode(1)

print merge_sorted_lists(node1, node2)

list1 = [1, 5, 7, 10]
list2 = [2, 4, 9, 13, 20, 30]

print merge_sorted_lists_wrong(list1, list2)
