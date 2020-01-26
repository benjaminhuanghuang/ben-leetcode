/*
107. Binary Tree Level Order Traversal II
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

reference:
    102. Binary Tree Level Order Traversal  
*/
using System.Linq;
using System.Collections.Generic;

public class Solution107 {
    public IList<IList<int>> LevelOrderBottom(TreeNode root) 
    {
        var res = new List<IList<int>>();
        var curlevel = new Queue<TreeNode>();
        var nextLevel = new Queue<TreeNode>();
        if (root != null)
        {
            curlevel.Enqueue(root);
        }

        while (curlevel.Any())
        {
            var values = new List<int>();
            while (curlevel.Any())
            {
                var cur = curlevel.Dequeue();

                values.Add(cur.val);
                if (cur.left != null)
                {
                    nextLevel.Enqueue(cur.left);
                }
                if (cur.right != null)
                {
                    nextLevel.Enqueue(cur.right);
                }
            }

            res.Add(values);
            while (nextLevel.Any())
            {
                curlevel.Enqueue(nextLevel.Dequeue());
            }
        }

        res.Reverse();   // Only Difference.
        return res;
    }
}