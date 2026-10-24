package cn.huang.leetcode;

import cn.huang.leetcode.common.ListNode;

/*
143. Reorder List

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.

Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.


 */
public class LC_0143_ReorderList {
    /*
    / 1. divide the linked list into two parts
    // 2. reverse the right part of the linked list
    // 3. combine two linked list one by one together

     */
    public void reorderList(ListNode head) {
        if (head == null || head.next == null)
        {
            return;
        }

        // step 1
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }

        // step 2, remember to set slow.next to null!
        ListNode rightPart = reverseList(slow.next);
        slow.next = null;

        // step 3, combine
        ListNode leftPart = head;
        while (leftPart != null && rightPart != null)
        {
            ListNode next = leftPart.next;
            leftPart.next = rightPart;
            rightPart = rightPart.next;
            leftPart.next.next = next;
            leftPart = next;
        }
    }
    private ListNode reverseList(ListNode head)
    {
        if (head == null || head.next == null)
        {
            return head;
        }

        ListNode pre = head;
        ListNode curr = head.next;

        while (curr != null)
        {
            ListNode temp = curr.next;
            curr.next = pre;
            pre = curr;
            curr = temp;
        }

        // set head node's next
        head.next = null;

        return pre;
    }
}
