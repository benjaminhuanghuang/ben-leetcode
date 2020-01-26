/*
109.  Convert Sorted List to Binary Search Tree  

*/

public class Solution109 {
    public TreeNode SortedListToBST(ListNode head) 
    {
        if (head == null)
        {
            return null;
        }

        var tail = head;
        while (tail.next != null)
        {
            tail = tail.next;
        }

        return sortedListToBSTRecursion(head, tail);
    }

    private TreeNode sortedListToBSTRecursion(ListNode head, ListNode tail)
    {
        if (head == null || tail == null || head == tail.next)
        {
            return null;
        }

        var slow = head;
        ListNode preslow = null;
        var fast = head;
        while (fast != tail && fast.next != tail)
        {
            preslow = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        var newNode = new TreeNode(slow.val);
        newNode.left = this.sortedListToBSTRecursion(head, preslow);
        newNode.right = this.sortedListToBSTRecursion(slow.next, tail);

        return newNode;
    }
}


