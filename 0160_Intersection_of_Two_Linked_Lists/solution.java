package cn.huang.leetcode;

import cn.huang.leetcode.common.ListNode;

/*
 160. Intersection of Two Linked Lists
 Write a program to find the node at which the intersection of two singly linked lists begins.

 */
public class LC_0160_IntersectionofTwoLinkedLists {
    /*
    https://www.youtube.com/watch?v=1bWqD_MwWuw

    让两条链表分别从各自的开头开始往后遍历，当其中一条遍历到末尾时，我们跳到另一个条链表的开头继续遍历。
    两个指针最终会相等，而且只有两种情况，一种情况是在交点处相遇，另一种情况是在各自的末尾的空节点处相等。
    为什么一定会相等呢，因为两个指针走过的路程相同，是两个链表的长度之和，所以一定会相等。
     */
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null)
            return null;

        ListNode listA = headA, listB = headB;

        while (listA != null && listB != null) {
            if (listA == listB)
                return listA;
            listA = listA.next;
            listB = listB.next;
            if (listA == listB) return listA;
            if (listA == null) listA = headB;
            if (listB == null) listB = headA;
        }
        return listA;
    }

    /*
    分别遍历两个链表，得到分别对应的长度。然后求长度的差值，把较长的那个链表向后移动这个差值的个数，然后一一比较即可
     */
    public ListNode getIntersectionNode_Faster(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;
        int lenA = getLength(headA), lenB = getLength(headB);
        if (lenA > lenB) {
            while (lenA != lenB) {
                headA = headA.next;
                lenA--;
            }
        } else {
            while (lenA != lenB) {
                headB = headB.next;
                lenB--;
            }
        }
        while (headA != null && headB != null && headA != headB) {
            headA = headA.next;
            headB = headB.next;
        }
        return (headA != null && headB != null) ? headA : null;
    }

    public int getLength(ListNode head) {
        int len = 0;
        while (head != null) {
            ++len;
            head = head.next;
        }
        return len;
    }
}
