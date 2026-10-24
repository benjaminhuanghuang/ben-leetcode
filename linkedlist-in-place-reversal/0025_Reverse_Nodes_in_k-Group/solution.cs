/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution025 {
    public ListNode ReverseKGroup(ListNode head, int k) {
        if(head == null || k == 1) 
            return head;

        var newHead = new ListNode(0){next = head};
        var start = newHead;
        while(start.next != null){
            var end = start;
            for (int i = 0; i < k-1; i++)
            {
                end = end.next;
                if (end.next == null)
                {
                    return newHead.next;
                }
            }
            var endBk = end.next;
            var startBk = start.next;
            this.Reverse(start.next, end.next);
            start.next = endBk;
            start = startBk;
        }
        return newHead.next;
    }
    private void Reverse(ListNode start, ListNode end)
    {
        var newHead = new ListNode(0){next = start};
        while( newHead.next != end)
        {
            var temp = start.next;
            start.next = temp.next;
            temp.next = newHead.next;
            newHead.next = temp;
        }
    }
}