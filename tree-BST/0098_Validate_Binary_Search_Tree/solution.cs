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