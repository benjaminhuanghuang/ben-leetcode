package cn.huang.leetcode;

import cn.huang.leetcode.common.ListNode;

/*
86. Partition List
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5


 */
public class LC_0086_PartitionList {
    public ListNode partition(ListNode head, int x) {
        ListNode headSmall = new ListNode(-1);
        ListNode headBig = new ListNode(-1);

        ListNode pSmall = headSmall;
        ListNode pBig = headBig;
        ListNode curr = head;
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
