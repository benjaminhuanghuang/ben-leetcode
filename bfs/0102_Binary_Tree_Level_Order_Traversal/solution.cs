/*
102. Binary Tree Level Order Traversal

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/
using System.Collections.Generic;

public class Solution102 {
    public IList<IList<int>> LevelOrder(TreeNode root) {
        var valuesList = new List<IList<int>>();
        var currentQueue = new Queue<TreeNode>();
        var nextQueue = new Queue<TreeNode>();

        if (root != null)
        {
            currentQueue.Enqueue(root);
        }

        while (currentQueue.Count > 0)
        {
            var values = new List<int>();
            while (currentQueue.Count > 0)
            {
                var node = currentQueue.Dequeue();
                values.Add(node.val);

                if (node.left != null)
                {
                    nextQueue.Enqueue(node.left);
                }

                if (node.right != null)
                {
                    nextQueue.Enqueue(node.right);
                }
            }
            currentQueue = nextQueue;
            nextQueue = new Queue<TreeNode>();
            // while (next.Any())
            // {
            //     cur.Enqueue(next.Dequeue());
            // }
            valuesList.Add(values);
        }

        return valuesList;
    }
}