//https://miafish.wordpress.com/2014/12/03/detect-and-find-beginning-of-the-loop-in-a-linked-list/
//http://blog.csdn.net/kenden23/article/details/13871699
/*
    when slow meed fast, slow pass l1+l2, fast pass l1 + l2 + n*c
    2*(l1+l2) = l1 + l2 + n*c   => l1 = (n - 1) * C + (C - l2) = > l1 = C-l2
 */
public class Solution142 {
    public ListNode DetectCycle(ListNode head) {
        var fast = head;
        var slow = head;
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
