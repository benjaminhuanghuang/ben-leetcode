/*
24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, 
only nodes itself can be changed.
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution024 {
    public ListNode SwapPairs(ListNode head) {
        if (head == null)
            return null;

        ListNode dummyhead = new ListNode(-1);
        ListNode tail = dummyhead;

        while (head !=null && head.next != null)
        {
            var nextStart = head.next.next;
            tail.next = head.next;
            tail.next.next = head;
            head.next = nextStart;

            tail = tail.next.next;
            head = nextStart;
        }
        if(head != null)
        {
            tail.next = head;
        }

        return dummyhead.next;
    }
    // Easy to understand!
    public ListNode SwapPairs_1(ListNode head)
    {
        var fakeHead = new ListNode(-1) { next = head };
        var start = fakeHead;
        while (start != null && start.next != null && start.next.next != null)
        {
            var end = start.next.next;
            start.next.next = end.next;
            end.next = start.next;
            start.next = end;

            start = start.next.next;
        }

        return fakeHead.next; 
    }

    public ListNode SwapPairs_Recursively(ListNode head)
    {
        if (head == null || head.next == null) return head;

        var newhead = head.next;
        head.next = SwapPairs_Recursively(head.next.next);
        newhead.next = head;
        return newhead;
    }
}

