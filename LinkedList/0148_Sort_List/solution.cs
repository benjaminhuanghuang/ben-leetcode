/*
148. Sort List

*/

public class Solution148 {
    public ListNode SortList(ListNode head) {
        if (head == null || head.next == null)
        {
            return head;
        }
        // Divide linked list to two parts
        var slow = head;
        var fast = head.next;
        while (fast!= null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }

        var secondhead = slow.next;
        slow.next = null;
        var firstPart = SortList(head);
        var secondPart = SortList(secondhead);

        return MergeLinkedList(firstPart, secondPart);
    }

    public ListNode MergeLinkedList(ListNode l1, ListNode l2)
    {
        var head = new ListNode(0);
        var start = head;

        while (l1 != null && l2 != null)
        {
            if (l1.val <= l2.val)
            {
                start.next = l1;
                l1 = l1.next;
            }
            else
            {
                start.next = l2;
                l2 = l2.next;
            }

            start = start.next;
        }

        if (l1 != null)
        {
            start.next = l1;
        }

        if (l2 != null)
        {
            start.next = l2;
        }

        return head.next;
    }
}

