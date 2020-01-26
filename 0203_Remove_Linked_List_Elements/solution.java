package cn.huang.leetcode;
/*
    203. Remove Linked List Elements

 */

import cn.huang.leetcode.common.ListNode;

public class LC_0203_RemoveLinkedListElements {
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummy = new ListNode(0);

        dummy.next = head;
        ListNode curr = dummy;

        while (curr != null && curr.next != null)
        {
            if (curr.next.val == val) {
                curr.next = curr.next.next;
            }
            else
                curr = curr.next;
        }
        return dummy.next;
    }
}