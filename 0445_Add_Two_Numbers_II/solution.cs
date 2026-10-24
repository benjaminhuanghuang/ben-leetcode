public class PartialSum{
    public ListNode Sum = null;
    public int Carry = 0;
}

public class Solution445 {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        int len1 = GetLength(l1);
        int len2 = GetLength(l2);

        if(len1 < len2)
        {
            l1 = PadList(l1, len2 - len1);
        }
        else
        {
            l2 = PadList(l2, len1 - len2);
        }

        PartialSum sum = AddListHelper(l1, l2);

        if (sum.Carry == 0)
            return sum.Sum;
        else
        {
            ListNode result = InsertBefore(sum.Sum, sum.Carry);
            return result;
        }
    }

    private int GetLength(ListNode n)
    {
        int len =0;
        while(n != null)
        {
            len ++;
            n = n.next;
        }
        return len;
    }
    private ListNode PadList(ListNode n, int padding)
    {
        ListNode head = n;
        for(int i=0; i < padding; i++)
        {
            ListNode newNode = new ListNode(0);
            newNode.next = head;
            head = newNode;
        }
        return head;
    }

    private PartialSum AddListHelper(ListNode l1, ListNode l2)
    {
        if( l1 == null && l2 == null)
        {
            return new PartialSum();
        }
        PartialSum sum = AddListHelper(l1.next, l2.next);
        int val = sum.Carry + l1.val + l2.val;
        ListNode fullResult = InsertBefore(sum.Sum, val %10);

        sum.Sum = fullResult;
        sum.Carry = val / 10;
        return sum;
    }

    private ListNode InsertBefore(ListNode n, int data)
    {
        ListNode newNode = new ListNode(data);
        newNode.next = n;
        return newNode;
    }

}