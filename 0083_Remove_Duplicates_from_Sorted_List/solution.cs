/*
83. Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.


*/

public class Solution083 {
    public ListNode DeleteDuplicates(ListNode head) {
        if (head == null || head.next == null)
            return head;;

        var curr = head;
        while (curr.next != null)
        {
            var next = curr.next;
            if (next.val == curr.val)
                curr.next = curr.next.next;
            else
                curr = next;
        }
        return head;
    }
}