/*
234. Palindrome Linked List

Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

using System;

public class Solution234
{
    // Method space O(N)
    // put all values in a array, then check the values
    public class Result
    {
        public bool result;
        public ListNode Node;

        public Result(ListNode n, bool r)
        {
            Node = n;
            result = r;
        }
    }
    public bool IsPalindrome(ListNode head)
    {
        Result p = this.IsPalindromeRecurse(head, Listsize(head));
        return p.result;
    }

    internal Result IsPalindromeRecurse(ListNode head, int length)
    {
        if (head == null || length == 0)
        {
            return new Result(null, true);
        }
        else if (length == 1)
        {
            return new Result(head.next, true);
        }
        else if (length == 2)
        {
            return new Result(head.next.next, head.val == head.next.val);
        }

        Result res = this.IsPalindromeRecurse(head.next, length - 2);
        if (!res.result || res.Node == null)
        {
            return res;
        }
        else
        {
            res.result = head.val == res.Node.val;
            res.Node = res.Node.next;
            return res;
        }
    }
    private int Listsize(ListNode rootNode)
    {
        var count = 0;
        while (rootNode != null)
        {
            rootNode = rootNode.next;
            count++;
        }

        return count;
    }
    // reverse the half part of the linked list and then use two points, one from, another from mid, 
    // scan and compare to check it is palindrome or not.
    public bool IsPalindrome_2(ListNode head)
    {
        if (head == null) return true;
        var length = 0;
        var start = head;
        while (start != null)
        {
            start = start.next;
            length++;
        }
        head = ReverseBetween(head, (int)Math.Ceiling(length / 2.0) + 1, length);

        var index = 1;
        var end = head;
        while (index < Math.Ceiling(length / 2.0) + 1)
        {
            end = end.next;
            index++;
        }

        start = head;
        while (end != null)
        {
            if (start.val != end.val)
            {
                return false;
            }

            end = end.next;
            start = start.next;
        }

        return true;
    }
    public ListNode ReverseBetween(ListNode head, int m, int n)
    {
        var fakehead = new ListNode(-1);
        fakehead.next = head;

        var start = fakehead;
        var count = 1;
        while (count < m)
        {
            start = start.next;
            count++;
        }

        var next = start.next;
        while (count++ < n)
        {
            var firstNode = next.next;
            next.next = firstNode.next;
            firstNode.next = start.next;
            start.next = firstNode;
        }

        return fakehead.next;
    }
}