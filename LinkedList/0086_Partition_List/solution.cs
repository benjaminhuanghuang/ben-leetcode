public class Solution086 {
    public ListNode Partition(ListNode head, int x) {
         var headSmall = new ListNode(-1);
         var headBig = new ListNode(-1);
         
         var pSmall = headSmall;
         var pBig = headBig;
         var curr = head;
         while(curr != null)
         {
             if (curr.val < x)
             {
                pSmall.next = curr;
                curr = curr.next;
                pSmall = pSmall.next;
                pSmall.next = null;       
             }
             else
             {
                pBig.next = curr;
                curr = curr.next;
                pBig = pBig.next;
                pBig.next = null;
             }
         }
         pSmall.next = headBig.next;
         head = headSmall.next;
         return head;       
    }
}

