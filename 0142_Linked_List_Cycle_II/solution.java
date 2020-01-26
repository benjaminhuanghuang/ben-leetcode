package cn.huang.leetcode;

import cn.huang.leetcode.common.ListNode;

/*
142. Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed)
in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.
 */
public class LC_0142_LinkedListCycle_II {
    /*
        https://miafish.wordpress.com/2014/12/03/detect-and-find-beginning-of-the-loop-in-a-linked-list/
        //http://blog.csdn.net/kenden23/article/details/13871699

        when slow meed fast, slow pass l1+l2, fast pass l1 + l2 + n*c
        2*(l1+l2) = l1 + l2 + n*c   => l1 = (n - 1) * C + (C - l2) = > l1 = C-l2
     */
    public ListNode detectCycle(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        while (fast != null && fast.next != null)
        {
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow)
            {
                fast = head;
                while (fast != slow)
                {
                    fast = fast.next;
                    slow = slow.next;
                }
                return slow;
            }
        }
        return null;
    }
}
