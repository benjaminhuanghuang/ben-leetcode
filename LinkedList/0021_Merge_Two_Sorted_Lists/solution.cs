/*
21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. The new list 
should be made by splicing together the nodes of the first two lists.
*/

public class Solution021 {
    public ListNode MergeTwoLists(ListNode l1, ListNode l2) {
        var dummyheader = new ListNode(-1);  // Importent
        var curr = dummyheader;
        while (l1!=null && l2!= null)
        {
            if (l1.val < l2.val)
            {
                curr.next = l1;
                l1 = l1.next;
            }
            else
            {
                curr.next = l2;
                l2 = l2.next;
            }
            curr = curr.next;
        }
        if (l1 != null)
            curr.next = l1;
        if (l2 != null)
            curr.next = l2;

        return dummyheader.next;
    }
}