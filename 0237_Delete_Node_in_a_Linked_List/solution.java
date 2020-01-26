package cn.huang.leetcode;
/*
    237. Delete Node in a Linked List
*/

import cn.huang.leetcode.common.ListNode;

public class LC_0237_DeleteNodeinaLinkedList {
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
