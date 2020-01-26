package cn.huang.leetcode;

import cn.huang.leetcode.common.ListNode;

/*
148. Sort List

Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4

Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5


 */
public class LC_0148_SortList {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        // Divide linked list to two parts
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode secondhead = slow.next;
        slow.next = null;
        ListNode firstPart = sortList(head);
        ListNode secondPart = sortList(secondhead);

        return mergeLinkedList(firstPart, secondPart);
    }

    public ListNode mergeLinkedList(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode start = head;

        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                start.next = l1;
                l1 = l1.next;
            } else {
                start.next = l2;
                l2 = l2.next;
            }

            start = start.next;
        }

        if (l1 != null) {
            start.next = l1;
        }

        if (l2 != null) {
            start.next = l2;
        }

        return head.next;
    }

    /*
    https://www.youtube.com/watch?v=M1TwY0nsTZA
     */


}
