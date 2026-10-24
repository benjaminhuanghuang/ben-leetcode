# coding: utf-8
'''
138. Copy List with Random Pointer

A linked list is given such that each node contains an additional random pointer which could point to any node
in the list or null.

Return a deep copy of the list.
'''


# Definition for singly-linked list with a random pointer.
class RandomListNode(object):
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None


class Solution(object):
    # http://www.kancloud.cn/kancloud/data-structure-and-algorithm-notes/73016
    # old list中的随机指针指向的是原链表中的节点，深拷贝则要求将随机指针指向new list中的节点。
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """

        if head == None:
            return None

        old_new_map = {}
        new_head = RandomListNode(head.label)
        old_new_map[head] = new_head
        p_old = head
        p_new = new_head

        while p_old != None:
            p_new.random = p_old.random
            if p_old.next != None:
                p_new.next = RandomListNode(p_old.next.label)
                old_new_map[p_old.next] = p_new.next
            else:
                p_new.next = None
            p_old = p_old.next
            p_new = p_new.next

        p = new_head
        while p != None:
            if p.random != None:
                p.random = old_new_map[p.random]
            p = p.next
        return new_head
