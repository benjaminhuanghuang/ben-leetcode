/*
110. Balanced Binary Tree  

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which 
the depth of the two subtrees of every node never differ by more than 1.

*/
using System;

public class Solution110 {
    public bool IsBalanced(TreeNode root) {
        if (root == null)
        {
            return true;
        }

        if (Math.Abs(this.GetHeight(root.left) - this.GetHeight(root.right)) < 2)
        {
            return this.IsBalanced(root.left) && this.IsBalanced(root.right);
        }

        return false;
    }

    private int GetHeight(TreeNode root)
    {
        if (root == null)
        {
            return 0;
        }

        return Math.Max(this.GetHeight(root.left), this.GetHeight(root.right)) + 1;
    }
    public bool IsBalanced2(TreeNode root)
    {
        if (root == null) 
        return true;
        var left = IsBalancedHelper(root.left);
        var right = IsBalancedHelper(root.right);

        if (left == -1 || right == -1) 
            return false;
        if (Math.Abs(left - right) >= 2) 
            return false;

        return true;
    }

    private int IsBalancedHelper(TreeNode root)
    {
        if (root == null) return 0;

        var left = IsBalancedHelper(root.left);
        var right = IsBalancedHelper(root.right);

        if (left == -1 || right == -1) 
            return -1;
        if (Math.Abs(left - right) >= 2) 
            return -1;

        return Math.Max(left, right) + 1;
    }
}
