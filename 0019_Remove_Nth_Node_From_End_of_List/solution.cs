/*
19. Remove Nth Node From End of List

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution019 {
    public ListNode RemoveNthFromEnd(ListNode head, int n) {
        var dummyhead = new ListNode(-1) { next = head };
        var start = dummyhead;
        var end = dummyhead;

        var i = 0;
        while (i < n)
        {
            end = end.next;
            i++;
        }

        while (end != null && end.next != null)
        {
            end = end.next;
            start = start.next;
        }

        start.next = start.next.next;
        return dummyhead.next;
    }
}