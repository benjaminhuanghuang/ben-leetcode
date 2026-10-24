package cn.huang.leetcode;

import cn.huang.leetcode.common.ListNode;

/*
25. Reverse Nodes in k-Group

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes
is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

    Only constant extra memory is allowed.
    You may not alter the values in the list's nodes, only nodes itself may be changed.


 */
public class LC_0025_ReverseNodesinkGroup {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        head = dummy;
        while (true) {
            head = reverseK(head, k);
            if (head == null) {
                break;
            }
        }

        return dummy.next;
    }
    // head -> n1 -> n2 ... nk -> nk+1
    // =>
    // head -> nk -> nk-1 .. n1 -> nk+1
    // return n1
    public ListNode reverseK(ListNode head, int k) {
        ListNode nk = head;
        for (int i = 0; i < k; i++) {
            if (nk == null) {
                return null;
            }
            nk = nk.next;
        }

        if (nk == null) {
            return null;
        }

        // reverse
        ListNode n1 = head.next;
        ListNode nkplus = nk.next;

        ListNode prev = null;
        ListNode curt = n1;
        while (curt != nkplus) {
            ListNode temp = curt.next;
            curt.next = prev;
            prev = curt;
            curt = temp;
        }

        // connect
        head.next = nk;
        n1.next = nkplus;
        return n1;
    }
}
