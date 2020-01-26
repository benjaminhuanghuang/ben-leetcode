/*
2. Add Two Numbers

You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

refer to #415. Add Strings
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
 
public class Solution002 {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(-1);
        var curr = head; 
        int carry = 0;
        while (l1 != null || l2 != null)
        {
            int a = 0;
            if (l1!=null)
            {
                a = l1.val;
                l1 = l1.next;
            }
            int b = 0;
            if (l2 != null)
            {
                b = l2.val;
                l2 = l2.next;
            }
            int sum = a + b + carry;
            carry = sum / 10;
            curr.next = new ListNode(sum % 10);
            curr = curr.next;
        }
        if (carry > 0)
        {
            curr.next = new ListNode(carry);
        }

        return head.next;
    }
}