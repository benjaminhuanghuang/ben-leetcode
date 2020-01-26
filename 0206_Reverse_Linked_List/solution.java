package cn.huang.leetcode;

import cn.huang.leetcode.common.ListNode;

/*
    206. Reverse Linked List
 */
public class LC_0206_ReverseLinkedList {
    public ListNode reverseList(ListNode head) {
        if (head == null)
            return null;

        ListNode previous = null;
        ListNode curr = head;
        ListNode next = head.next;

        while (next != null) {
            curr.next = previous;

            previous = curr;
            curr = next;
            next = next.next;
        }
        curr.next = previous;
        return curr;
    }

    public ListNode reverseList_V2(ListNode head) {
        if (head == null || head.next == null) return head;

        ListNode pre = head;
        ListNode p = head.next;
        pre.next = null;
        ListNode nxt;
        while (p != null) {
            nxt = p.next;
            p.next = pre;
            pre = p;
            p = nxt;
        }
        return pre;
    }

    public ListNode reverse(ListNode head) {
        if (head == null || head.next == null) return head;

        ListNode rest = reverse(head.next);
        //  head.next is the tail of the rest part after reverse
        //  Make the tail connect to head node
        head.next.next = head;
        head.next = null;
        return rest;
    }
}
