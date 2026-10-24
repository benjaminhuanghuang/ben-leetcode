/*
61. Rotate List

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

Test Case:
    [1,2,3]
    2000000000
    [1,2]
    1
*/

public class Solution061 {
    public ListNode RotateRight(ListNode head, int k) {
        if (head == null || k == 0)
            return head;
        ListNode p = head;

        int length = 1;
        while (p.next!=null)
        {
            p = p.next;
            length ++;
        }
        p.next = head;  // make a cycle
        int step = length - (k % length);
        //new p.next points to head;
        for (int i = 0; i < step; i++)
        {
            p = p.next;
        }
        head = p.next;
        p.next = null;
        return head;
    }
}