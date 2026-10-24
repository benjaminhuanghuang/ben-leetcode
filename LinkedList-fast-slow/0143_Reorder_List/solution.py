'''
143. Reorder List
Given a singly linked list L: L0, L1..Ln,
reorder it to: L0->ln->L1->Ln-1...

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.


Hint:
    Cut the linked list to two parts, reverse second part, then link those 2 parts

'''
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        if None == head or None == head.next:
            return

        pfast = head.next
        pslow = head

        # pfast points to the last node
        # pslow points to the middle of the list
        while pfast and pfast.next:
            pfast = pfast.next.next
            pslow = pslow.next

        # cut the list to two parts
        sec_head = pslow.next
        pslow.next = None

        # reverse second part
        next = sec_head.next
        sec_head.next = None
        while next:
            q = next.next
            next.next = sec_head
            sec_head = next
            next = q

        # merge 2 parts
        first_head = head
        while sec_head:
            next = sec_head.next
            sec_head.next = first_head.next
            first_head.next = sec_head
            first_head = first_head.next.next
            sec_head = next

s = Solution()
s.reorderList(ListNode(10))