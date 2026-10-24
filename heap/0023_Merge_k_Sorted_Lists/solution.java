package cn.huang.leetcode;

import cn.huang.leetcode.common.ListNode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

/*
23. Merge k Sorted Lists

 */

public class LC_0023_MergekSortedLists {
    /*
    https://www.youtube.com/watch?v=5xT5GMTFvRI
    https://www.youtube.com/watch?v=Uz4fTr34270

    PQ can return the min/max number in O(logN) time

    O(nlogK)  K is the numbers of the lists
    */
    public ListNode mergeKLists_pq(ListNode[] lists) {
        if (lists == null || lists.length == 0)
            return null;

        PriorityQueue<ListNode> queue = new PriorityQueue<>(lists.length, (a, b) -> a.val - b.val);
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        // insert all head into pq
        for (ListNode list : lists) {
            if (list != null) {
                queue.add(list);
            }
        }
        while (!queue.isEmpty()) {
            current.next = queue.poll();
            current = current.next;
            if (current.next != null) {
                queue.add(current.next);
            }
        }
        return dummy.next;
    }


    // O(nlogK)   l = list.length
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0)
            return null;

        return mergeKLists(lists, 0, lists.length - 1);
    }

    public ListNode mergeKLists(ListNode[] lists, int low, int high) {
        if (low >= high) return lists[low];
        int mid = (high - low) / 2 + low;
        ListNode l1 = mergeKLists(lists, low, mid);
        ListNode l2 = mergeKLists(lists, mid, high);

        return mergeLists(l1, l2);
    }

    public ListNode mergeLists(ListNode l1, ListNode l2) {
        if (l1 == null)
            return l2;
        if (l2 == null)
            return l1;

        if (l1.val < l2.val) {
            l1.next = mergeLists(l1.next, l2);
            return l1;
        }

        l2.next = mergeLists(l1, l2.next);
        return l2;
    }

    /*
    https://www.youtube.com/watch?v=Uz4fTr34270
    Time O(n*k*log(n*k))    n 是list 的平均长度，k是list个数 n*k是node总数量
    Space O(n*k)
    */
    public ListNode mergeKLists_Naive(ListNode[] lists) {
        if (lists == null || lists.length == 0)
            return null;

        List<Integer> allNodes = new ArrayList<>();
        for (ListNode node : lists) {
            while (node != null) {
                allNodes.add(node.val);
                node = node.next;
            }
        }
        Collections.sort(allNodes);

        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        for (Integer val : allNodes) {
            ListNode temp = new ListNode(val);
            current.next = temp;
            current = current.next;
        }

        return dummy.next;
    }

    /*
   https://www.youtube.com/watch?v=Uz4fTr34270
   Time O(n*k)    n 是list 的平均长度，k是list个数 n*k是node总数量
   Space O(1)

   Find the smallest node in all of lists head
   */
    public ListNode mergeKLists_2(ListNode[] lists) {
        if (lists == null || lists.length == 0)
            return null;

        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        ListNode tmp = null;

        do {
            tmp = findMinAndMove(lists);
            current.next = tmp;
            current = current.next;
        } while (tmp != null);

        return dummy.next;

    }

    public ListNode findMinAndMove(ListNode[] lists) {
        if (lists == null || lists.length == 0)
            return null;

        int minVal = Integer.MAX_VALUE;
        int ret_i = -1;
        for (int i = 0; i < lists.length; i++) {
            if (lists[i] == null)
                continue;
            if (lists[i].val < minVal) {
                minVal = lists[i].val;
                ret_i = i;
            }
        }

        ListNode retNode = null;
        if (ret_i != -1) {
            retNode = lists[ret_i];
            lists[ret_i] = lists[ret_i].next;
        }
        return retNode;
    }
}
