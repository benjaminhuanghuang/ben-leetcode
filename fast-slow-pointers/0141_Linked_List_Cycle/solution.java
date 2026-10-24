package cn.huang.leetcode;

import cn.huang.leetcode.common.ListNode;

public class LC_0141_LinkedListCycle {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while(slow != null && fast != null && fast.next != null) {
            slow = slow.next;               //Slow moves by 1 step
            fast = fast.next.next;        //Fast moves by two steps
            //If they meet then there is a loop
            if(slow == fast)
            {
               return true;
            }
        }
        return false;
    }
}
