'''
142. Linked List Cycle II

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

https://shenjie1993.gitbooks.io/leetcode-python/content/142%20Linked%20List%20Cycle%20II.html
'''


class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


# http://bookshadow.com/weblog/2015/07/10/leetcode-linked-list-cycle-ii/
# when slow meed fast, slow pass l1+l2, fast pass l1 + l2 + n*c
# 2*(l1+l2) = l1 + l2 + n*c   => l1 = (n - 1) * C + (C - l2) = > l1 = C-l2
class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return None

        slow = head
        fast = head.next

        while fast != slow:
            if not fast or not fast.next:
                return None
            slow = slow.next
            fast = fast.next.next

        while head != slow.next:  # when head meet with slow, we get the
            head = head.next
            slow = slow.next
        return head

    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                node = head
                while node != slow:
                    node = node.next
                    slow = slow.next
                return node
        return None


head = ListNode(1)
node = ListNode(2)
head.next = node
node.next = head

s = Solution()
s.detectCycle(head)
