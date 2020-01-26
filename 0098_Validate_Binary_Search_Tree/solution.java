package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*
98. Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

Example 1:

Input:
    2
   / \
  1   3
Output: true

Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.


 */
public class LC_0098_ValidateBinarySearchTree {

    public boolean isValidBST(TreeNode root) {
        return checkBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    // handle [2147483647]
    private boolean checkBST(TreeNode n, long min, long max) {
        if (n == null)
            return true;
        if (n.val <= min || n.val >= max)
            return false;

        if (!checkBST(n.left, min, n.val) || !checkBST(n.right, n.val, max))
            return false;
        return true;
    }

    //if use int type for previous, can not pass test when input is min int
    private long previous = Long.MIN_VALUE;

    public boolean IsValidBST(TreeNode root) {
        if (root == null)
            return true;

        if (!this.IsValidBST(root.left))
            return false;

        if (previous >= root.val)
            return false;
        previous = root.val;
        return this.IsValidBST(root.right);
    }

}
