/*
147. Insertion Sort List

Sort a linked list using insertion sort.
*/

public class Solution147 {
    public ListNode InsertionSortList(ListNode head) {
        var fakehead = new ListNode(-1){next = head};

        var start = fakehead.next;

        while (start != null && start.next != null)
        {
            var searchnode = fakehead;
            while (searchnode != start && searchnode.next.val <= start.next.val)
            {
                searchnode = searchnode.next;
            }
            
            // find insert point
            if (searchnode != start)
            {
                var temp = searchnode.next;
                searchnode.next = start.next;
                start.next = start.next.next;
                searchnode.next.next = temp;
            }
            // not find insert point
            else
            {
                start = start.next;
            }
        }

        return fakehead.next;
    }
}