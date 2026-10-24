/*
103. Binary Tree Zigzag Level Order Traversal

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

*/

using System.Collections.Generic;

public class Solution103 {
    public IList<IList<int>> ZigzagLevelOrder(TreeNode root) {
        var res = new List<IList<int>>();
        var currentQueue = new Queue<TreeNode>();
        var nextQueue = new Queue<TreeNode>();

        if (root != null)
        {
            currentQueue.Enqueue(root);
        }

        var leftToRight = true;
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
            foreach (var node in nextQueue)
            {
                currentQueue.Enqueue(node);
            }
            nextQueue.Clear();

            if (!leftToRight)
            {
                values.Reverse();
            }

            res.Add(values);
            leftToRight = !leftToRight;
        }

        return res;
    }
}