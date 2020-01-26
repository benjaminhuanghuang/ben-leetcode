'''
109. Convert Sorted List to Binary Search Tree

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
'''
from data_structure.tree_node import TreeNode
from utilities.data_generator import *


class Solution(object):
    def sortedListToBST(self, head):
        if not head:
           return None
        if not head.next:
            return TreeNode(head.val)

        fast = head.next
        slow = head
        last_of_left = None
        while fast and fast.next:
            fast = fast.next.next
            last_of_left = slow
            slow = slow.next

        root = TreeNode(slow.val)

        if last_of_left:
            last_of_left.next = None
            root.left = self.sortedListToBST(head)

        if slow.next:
            root.right = self.sortedListToBST(slow.next)
        return root


    def sortedListToBST_2(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        self.cur = head
        node, length = head, 0
        while node:
            node = node.next
            length += 1
        return self.build_tree(length)

    def build_tree(self, n):
        if n <= 0:
            return None
        l = self.build_tree(n / 2)
        root = TreeNode(self.cur.val)
        self.cur = self.cur.next
        r = self.build_tree(n - n / 2 - 1)
        root.left = l
        root.right = r
        return root


s = Solution()
head = generate_list([1, 2, 3])
tree = s.sortedListToBST_2(head)
