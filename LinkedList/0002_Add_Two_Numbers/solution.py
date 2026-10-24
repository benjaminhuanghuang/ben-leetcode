'''
2. Add Two Numbers   [#67, #43]

You are given two linked lists representing two non-negative numbers. The digits are stored
in reverse order and each of their nodes contain a single digit. Add the two numbers and
return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

'''

from data_structure.list_node import ListNode


class Solution(object):
    def addTwoNumbers_my(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(0)
        curr = head
        carry = 0
        while True:
            sum = 0
            if l1 != None:
                sum += l1.val
                l1 = l1.next
            if l2 != None:
                sum += l2.val
                l2 = l2.next
            sum += carry
            curr.val = sum % 10
            carry /= 10
            if l1 != None or l2 != None or carry != 0:
                # Good! add a new node to add wi
                curr.next = ListNode(0)
                curr = curr.next
            else:
                break
        return head

    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(0)
        curr = head
        carry = 0
        while True:
            if l1 != None:
                carry += l1.val
                l1 = l1.next
            if l2 != None:
                carry += l2.val
                l2 = l2.next
            curr.val = carry % 10
            carry /= 10
            if l1 != None or l2 != None or carry != 0:
                # Good! add a new node to add wi
                curr.next = ListNode(0)
                curr = curr.next
            else:
                break
        return head

    def addTwoNumbers_2(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if not (l1 and l2):
            return None
        if not l1:
            return l2
        if not l2:
            return l1
        result = ListNode(-1)
        h = result
        curry = 0
        while l1 or l2:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0
            sum = v1 + v2 + curry
            h.next = ListNode(sum % 10)
            curry = sum / 10
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
            h = h.next
        if curry > 0:
            h.next = ListNode(curry)
        return result.next


from utilities import data_generator

s = Solution()
l1 = data_generator.generate_list([4, 3, 1])
l2 = data_generator.generate_list([4, 3, 1])

res = s.addTwoNumbers_2(l1, l2)
print res
