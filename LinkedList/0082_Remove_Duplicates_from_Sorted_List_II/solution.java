package cn.huang.leetcode;

import cn.huang.leetcode.common.ListNode;

/*
82. Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5

Example 2:

Input: 1->1->1->2->3
Output: 2->3


 */
public class LC_0082_RemoveDuplicatesfromSortedList_II {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null || head.next == null)
            return head;

        ListNode dummyNode = new ListNode(-1);
        ListNode prev = dummyNode;
        dummyNode.next = head;

        while(head != null && head.next != null)
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
        return dummyNode.next;
    }

}
