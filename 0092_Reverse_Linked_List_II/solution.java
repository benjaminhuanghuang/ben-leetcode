package cn.huang.leetcode;

import cn.huang.leetcode.common.ListNode;

/*
92. Reverse Linked List II
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
 */
public class LC_0092_ReverseLinkedList_II {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode dummyhead = new ListNode(-1);
        dummyhead.next = head;
        ListNode pre = dummyhead;

        // move start to m -1
        for (int i = 0; i < m - 1; i++) {
            pre = pre.next;
        }
        ListNode curr = pre.next;
        /*
            1 2 3 4 5
            p c t

            1 3 2 4 5
            p   c t
         */
        for (int i = 0; i < n - m; i++) {
           ListNode temp = curr.next;
           curr.next = temp.next;
           temp.next = pre.next;
           pre.next = temp;
        }

        return dummyhead.next;
    }
}
