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