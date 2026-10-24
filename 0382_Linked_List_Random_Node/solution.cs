using System;

public class Solution382
{
    private ListNode head;

    public Solution382(ListNode head)
    {
        this.head = head;
    }

    public int GetRandow()
    {
        int ans = 0;
        int count = 0;
        ListNode curr = this.head;
        Random rnd = new Random();
        while(curr != null)
        {
            if(rnd.Next(0, count) == 0)
                ans = curr.val;
            curr = curr.next;
            count ++;
        }
        return ans;
    }

}