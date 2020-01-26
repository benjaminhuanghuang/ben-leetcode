/*
98. Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.

*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */

using System;

public class Solution098 {
    // if use int type, can not pass test when input is min int
    private int previous = int.MinValue;
    public bool IsValidBST(TreeNode root) {
        if (root == null)
            return true;
      
        if (!this.IsValidBST(root.left))
            return false;
        //if use int type for previous, can not pass test when input is min int
        if (previous >= root.val)
            return false;
        previous = root.val;
        return this.IsValidBST(root.right);
    }

    public bool IsValidBST_2(TreeNode root) {
        return CheckBST(root, long.MinValue, long.MaxValue);
    }

    private bool CheckBST(TreeNode n, long min, long max)
    {
        if (n == null)
            return true;
        if(n.val <= min || n.val >= max)
            return false;

        if (!CheckBST(n.left, min, n.val) || !CheckBST(n.right, n.val, max))
            return false;
        return true;
    }


}