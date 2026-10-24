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
