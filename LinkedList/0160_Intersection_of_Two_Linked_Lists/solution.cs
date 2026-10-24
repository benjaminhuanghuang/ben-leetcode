/*
    160. Intersection of Two Linked Lists

    Write a program to find the node at which the intersection of two singly linked lists begins.


    For example, the following two linked lists:

    A:      a1 → a2
                    ↘
                        c1 → c2 → c3
                    ↗            
    B: b1 → b2 → b3
    begin to intersect at node c1.


    Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.
*/

public class Solution160 {
    public ListNode GetIntersectionNode(ListNode headA, ListNode headB) {
        int lenA = this.GetListLength(headA);
        int lenB = this.GetListLength(headB);

        if (lenA < lenB)
            return GetIntersectionNode(headB, headA);
            
        for(int i = 0; i < (lenA - lenB); i++)
            headA = headA.next;
        
        while(headA != null && headB != null)
        {
            if (headA == headB)
                return headA;
            headA = headA.next;
            headB = headB.next;
        }
        return null;
    }
    private int GetListLength(ListNode head)
    {
        if (head == null)
            return 0;
        int len = 0;
        while (head !=null)
        {
            len++;
            head = head.next;
        }
        return len;
    }
}