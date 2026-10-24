# coding: utf-8
'''
160. Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.

'''


class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        size_a = self.get_size(headA)
        size_b = self.get_size(headB)

        if size_a < size_b:
            return self.getIntersectionNode(headB, headA)

        for i in range(size_a - size_b):
            headA = headA.next

        while headA and headB:
            if headA == headB:
                return headA    # return here
            headA = headA.next
            headB = headB.next


    def get_size(self, head):
        if not head:
            return 0
        n = 0
        while head:
            n += 1
            head = head.next
        return n
