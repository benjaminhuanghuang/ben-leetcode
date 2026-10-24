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

public class Solution092 {
    public ListNode ReverseBetween(ListNode head, int m, int n) {        
        var fakehead = new ListNode(-1){next = head};
        var start = fakehead;
         // move start to m -1
        int i = 0;
        while (i < m -1)
        {
            start = start.next;
            i++;
        } 

        var count = m;
        var mNode = start.next;
        while (count < n)
        {
            // reverse linked list
            var firstNode = start.next;
            start.next = mNode.next;
            mNode.next = mNode.next.next;
            start.next.next = firstNode;

            count++;
        }

        return fakehead.next;
    }
}
