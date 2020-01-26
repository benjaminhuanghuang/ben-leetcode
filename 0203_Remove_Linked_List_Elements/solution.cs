/*
203. Remove Linked List Elements

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

public class Solution203 {
    public ListNode RemoveElements(ListNode head, int val) {
        if(head == null)
            return head;
        ListNode dummyHead = new ListNode(-1){next = head};
        var prev = dummyHead;
        var curr = head;
        while(curr != null)
        {   
            if (curr.val == val)
            {
                prev.next = curr.next;
                curr = prev.next;
            }
            else
            {
                prev = prev.next;
                curr = curr.next; 
            }
        }
        return dummyHead.next;
    }

    public ListNode RemoveElements_Better(ListNode head, int val)
    {
        var fakehead = new ListNode(-1) { next = head };

        var start = fakehead;

        while (start.next != null)
        {
            if (start.next.val == val)
            {
                start.next = start.next.next;
            }
            else
            {
                start = start.next;
            }
        }

        return fakehead.next;
    }
}