/*
86. Partition List

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

*/

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

