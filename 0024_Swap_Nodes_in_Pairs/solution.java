package cn.huang.leetcode;

import cn.huang.leetcode.common.ListNode;

/*

24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.

Note:

    Your algorithm should use only constant extra space.
    You may not modify the values in the list's nodes, only nodes itself may be changed.


 */
public class LC_0024_SwapNodesinPairs {
    public ListNode SwapPairs_Recursively(ListNode head) {
        if (head == null || head.next == null) return head;

        ListNode newhead = head.next;
        head.next = SwapPairs_Recursively(head.next.next);
        newhead.next = head;
        return newhead;
    }

    public ListNode SwapPairs(ListNode head) {
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;

        ListNode start = dummyHead;
        while (start != null && start.next != null && start.next.next != null) {
            ListNode end = start.next.next;
            start.next.next = end.next;
            end.next = start.next;
            start.next = end;

            start = start.next.next;
        }

        return dummyHead.next;
    }
}
