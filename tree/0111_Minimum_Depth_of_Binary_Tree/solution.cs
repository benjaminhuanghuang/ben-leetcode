/*
111. Minimum Depth of Binary Tree

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest 
leaf node.
*/
using System;
public class Solution111 {
    public int MinDepth(TreeNode root) 
    {
        if(root == null)
            return 0;

        if (root.left != null && root.right != null)
        {
            return Math.Min(this.MinDepth(root.left), this.MinDepth(root.right)) + 1;                
        }
        else if(root.left != null)
        {
            return this.MinDepth(root.left) + 1;
        }
        else
        {
            return this.MinDepth(root.right) + 1;
        }
    }
}