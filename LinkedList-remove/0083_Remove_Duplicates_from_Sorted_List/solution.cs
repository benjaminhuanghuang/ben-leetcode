public class Solution083 {
    public ListNode DeleteDuplicates(ListNode head) {
        if (head == null || head.next == null)
            return head;;

        var curr = head;
        while (curr.next != null)
        {
            var next = curr.next;
            if (next.val == curr.val)
                curr.next = curr.next.next;
            else
                curr = next;
        }
        return head;
    }
}