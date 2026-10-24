package cn.huang.leetcode;

import cn.huang.leetcode.common.ListNode;

/*
19. Remove Nth Node From End of List
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

 */
public class LC_0019_RemoveNthNodeFromEndofList {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummyhead = new ListNode(-1);
        dummyhead.next = head;
        ListNode start = dummyhead;
        ListNode end = dummyhead;

        int i = 0;
        while (i < n) {
            end = end.next;
            i++;
        }

        while (end.next != null) {
            end = end.next;
            start = start.next;
        }

        start.next = start.next.next;
        return dummyhead.next;
    }
}
