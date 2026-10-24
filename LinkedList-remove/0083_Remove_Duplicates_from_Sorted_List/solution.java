package cn.huang.leetcode;

/*
    83. Remove Duplicates from Sorted List
    Given a sorted linked list, delete all duplicates such that each element appear only once.

    Example 1:

    Input: 1->1->2
    Output: 1->2

    Example 2:

    Input: 1->1->2->3->3
    Output: 1->2->3
 */
import cn.huang.leetcode.common.ListNode;

public class LC_0083_RemoveDuplicatesfromSortedList {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null)
            return head;

        ListNode slow = head;
        ListNode fast = slow.next;

        while(fast != null)
        {
            if(fast.val == slow.val)
            {
                fast = fast.next;
                continue;
            }
            slow.next = fast;
            slow = fast;
            fast = fast.next;
        }
        slow.next = fast;
        return head;
    }

    public ListNode deleteDuplicates_much_better(ListNode head) {
        if(head == null)
            return head;

        ListNode current = head;

        while(current != null && current.next != null)
        {
            if(current.val == current.next.val)
                current.next = current.next.next;
            else
                current = current.next;
        }

        return head;
    }
}
