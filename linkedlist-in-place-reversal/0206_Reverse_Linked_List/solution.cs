/*
206. Reverse Linked List

Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution206 {
    public ListNode ReverseList_Recursively(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode rest = this.ReverseList_Recursively(head.next);
        //  head.next is the tail of the rest part after reverse
        //  Make the tail connect to head node
        head.next.next = head;
        head.next = null;
        return rest;
    }

    public ListNode ReverseList_Iteratively(ListNode head) {
        if (head == null || head.next == null)
            return head;
        
        // At beginning, newHead.next points null
        ListNode newHead = new ListNode(-1);
    
        while (head != null)
        {
            var next = head.next;
            head.next = newHead.next;
            newHead.next = head; 

            head = next;
        }

        return newHead.next;
    }
    public ListNode ReverseList_2(ListNode head) {
        if (head == null || head.next == null)
            return head;
        
        ListNode prev = null;
        ListNode curr = head;
        while(curr != null)
        {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
}