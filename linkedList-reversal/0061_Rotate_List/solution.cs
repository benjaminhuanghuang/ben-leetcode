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