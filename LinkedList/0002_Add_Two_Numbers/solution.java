package cn.huang.leetcode;

/*
2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

 */
import cn.huang.leetcode.common.ListNode;

public class LC_0002_AddTwoNumbers {
    public ListNode solve(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0), currNode = dummy;

        for (int carry = 0; l1 != null || l2 != null || carry > 0; ) {
            int n1 = l1 != null ? l1.val : 0;
            l1 = l1 != null ? l1.next : null;

            int n2 = l2 != null ? l2.val : 0;
            l2 = l2 != null ? l2.next : null;

            int sum = n1 + n2 + carry;
            ListNode newNode = new ListNode(sum % 10);
            carry = sum / 10;
            currNode.next = newNode;    // link the new node to the result list
            currNode = newNode;
        }

        return dummy.next;
    }
}
