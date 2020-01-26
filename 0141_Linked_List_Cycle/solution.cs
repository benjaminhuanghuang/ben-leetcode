/*
141. Linked List Cycle

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

*/

public class Solution141
{
    public bool HasCycle(ListNode head)
    {
        if (head == null)
            return false;
        var slow = head;
        var fast = head.next;

        while (fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast)
                return true;
        }

        return false;
    }
}
