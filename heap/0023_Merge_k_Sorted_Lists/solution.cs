/*
23. Merge k Sorted Lists

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
using System;
using System.Collections.Generic;

// https://miafish.wordpress.com/2015/01/27/leetcode-oj-c-merge-k-sorted-lists/
public class Solution023 {
    //  public ListNode MergeKLists_MiniHeap(ListNode[] lists) {
    //         var fakehead = new ListNode(-1);
    //         var start = fakehead;
    //         var heap = new Heap();

    //         foreach (var headnode in lists)
    //         {
    //             if (headnode != null)
    //             {
    //                 heap.Add(headnode);
    //             }
    //         }

    //         while (heap.Any())
    //         {
    //             var top = heap.GetMin();

    //             start.next = top;
    //             start = start.next;

    //             if (top.next != null)
    //             {
    //                 heap.Add(top.next);
    //             }
    //         }

    //         return fakehead.next; 
    // }

    // 最简单的办法就是扫一遍k个链表的开头，哪个最小就把它移除，加入到结果链表中。这样时间复杂度是kn
    public ListNode MergeKLists_Naive(ListNode[] lists) {
        var dummyhead = new ListNode(-1);
        
        return null;
    }

    // 将k个链表分为两个一组，组内进行merge。形成一个新的链表集合，大小为(k + 1)/2。继续两个一组merge，
    // 这样下去一共会进行logk次merge，最后merge成为一个链表。总的时间复杂度是nlogk
    public ListNode MergeKLists(ListNode[] lists) {
        int len = lists.Length;
        if (len ==0 )
            return null;
        if (len == 1)
            return lists[0];
        if (len == 2)
            return this.MergeTwoLists(lists[0], lists[1]);
        
        int mid = len / 2;
        var left = this.MergeTwoListsHelper(lists, 0 , mid);
        var right = this.MergeTwoListsHelper(lists, mid +1 , len -1);

        return this.MergeTwoLists(left, right);
    }

    private ListNode MergeTwoListsHelper(ListNode[] lists, int left, int right)
    {
        if (left > right)
            return null;
        if (left == right)
            return lists[left];

        var mid = (right - left) / 2 + left;
        var leftLists = MergeTwoListsHelper(lists, left, mid);
        var rightLists = MergeTwoListsHelper(lists, mid + 1, right);  

        return this.MergeTwoLists(leftLists, rightLists);
    }
    

    private ListNode MergeTwoLists(ListNode l1, ListNode l2)
    {
        var dummyhead = new ListNode(-1);
        var curr = dummyhead;
        while (l1 != null && l2!=null)
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
        return dummyhead.next;
    }
}