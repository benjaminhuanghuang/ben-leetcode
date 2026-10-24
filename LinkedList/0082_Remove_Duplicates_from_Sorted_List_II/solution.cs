/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution082 {
    public ListNode DeleteDuplicates(ListNode head) {
        var fakehead = new ListNode(-1) {next = head};

        var begin = fakehead;
        var end = fakehead.next;

        var isDuplicate = false;
        while (end != null)
        {
            if (end.next != null && begin.next.val == end.next.val)
            {
                isDuplicate = true;
            }
            else
            {
                if (isDuplicate)
                {
                    begin.next = end.next;
                    isDuplicate = false;
                }
                else
                {
                    begin = begin.next;
                }
            }

            end = end.next;
        }

        return fakehead.next;
    }

    public ListNode DeleteDuplicates_2(ListNode head) {
        if (head == null || head.next==null)
            return head;
        var dummy = new ListNode(-1){next = head};
        var prev = dummy;
        while (head != null && head.next!= null)
        {
            if (head.val == head.next.val)
            {
                int value = head.val;
                while (head!=null && head.val == value)
                    head = head.next;
                prev.next = head;
            }
            else
            { 
                head = head.next;
                prev = prev.next;
            }
        }

        return dummy.next;
    }
}