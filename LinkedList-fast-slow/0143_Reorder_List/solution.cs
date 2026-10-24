/*
143. Reorder List

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

public class Solution143 {

    // 1. divide the linked list into two parts
    // 2. reverse the right part of the linked list
    // 3. combine two linked list one by one together
    public void ReorderList(ListNode head) {
        if (head == null || head.next == null)
        {
            return;
        }

        // step 1
        var slow = head;
        var fast = head;
        while (fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }

        // step 2, remember to set slow.next to null!
        var rightPart = ReverseOrder(slow.next);
        slow.next = null;

        // step 3, combine
        var leftPart = head;
        while (leftPart != null && rightPart != null)
        {
            var temp = leftPart.next;
            leftPart.next = rightPart;
            rightPart = rightPart.next;
            leftPart.next.next = temp;
            leftPart = temp;
        }
    }

    public static ListNode ReverseOrder(ListNode head)
    {
        if (head == null || head.next == null)
        {
            return head;
        }

        ListNode pre = head;
        ListNode curr = head.next;

        while (curr != null)
        {
            ListNode temp = curr.next;
            curr.next = pre;
            pre = curr;
            curr = temp;
        }

        // set head node's next
        head.next = null;

        return pre;
    }
}
