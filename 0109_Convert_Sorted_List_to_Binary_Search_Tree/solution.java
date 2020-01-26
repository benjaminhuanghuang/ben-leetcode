package cn.huang.leetcode;

import cn.huang.leetcode.common.ListNode;
import cn.huang.leetcode.common.TreeNode;

/*
109. Convert Sorted List to Binary Search Tree


Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees
of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5


 */
public class LC_0109_ConvertSortedListtoBinarySearchTree {
    public TreeNode sortedListToBST(ListNode head) {

        if (head == null) {
            return null;
        }

        ListNode tail = head;
        while (tail.next != null) {
            tail = tail.next;
        }

        return sortedListToBSTRecursion(head, tail);
    }

    private TreeNode sortedListToBSTRecursion(ListNode head, ListNode tail) {
        if (head == null || tail == null || head == tail.next) {
            return null;
        }

        ListNode slow = head;
        ListNode preslow = null;
        ListNode fast = head;
        while (fast != tail && fast.next != tail) {
            preslow = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        TreeNode root = new TreeNode(slow.val);
        root.left = this.sortedListToBSTRecursion(head, preslow);
        root.right = this.sortedListToBSTRecursion(slow.next, tail);

        return root;
    }
}
