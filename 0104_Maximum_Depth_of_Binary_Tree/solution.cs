/*
104. Maximum Depth of Binary Tree

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to 
the farthest leaf node.


*/
using System;
using System.Linq;
using System.Collections.Generic;

public class Solution104 {
    // DFS
    public int MaxDepth(TreeNode root) {
        if (root == null) return 0;
        return Math.Max(this.MaxDepth(root.left), this.MaxDepth(root.right)) + 1;
    }

    public int MaxDepth_BFS(TreeNode root) 
    {
        var res = 0;
        var queue = new Queue<TreeNode>();
        if(root != null) queue.Enqueue(root);

        while (queue.Any())
        {
            var size = queue.Count;
            res++;
            for (int i = 0; i < size; i++)
            {
                var top = queue.Dequeue();

                if (top.left != null)
                {
                    queue.Enqueue(top.left);
                }

                if (top.right != null)
                {
                    queue.Enqueue(top.right);
                }
            }
        }

        return res;    
    }
}