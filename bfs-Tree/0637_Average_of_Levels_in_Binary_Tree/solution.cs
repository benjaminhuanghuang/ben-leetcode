/*
 637. Average of Levels in Binary Tree
    # 102. Binary Tree Level Order Traversal       
 Given a non-empty binary tree, return the average value of the nodes on each level in the form 
 of an array.

Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. 
Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
 */
using System.Collections.Generic;
using System.Linq;

public class Solution637
{
    public IList<double> AverageOfLevels(TreeNode root)
    {
        List<double> res = new List<double>();
        var currentQueue = new Queue<TreeNode>();
        var nextQueue = new Queue<TreeNode>();
        double sum =0;
        int count = 0;
        if (root != null)
        {
            currentQueue.Enqueue(root);
        }

        while (currentQueue.Count > 0)
        {
            sum = 0;
            count =0;
            while (currentQueue.Count > 0)
            {
                var node = currentQueue.Dequeue();
                sum += node.val;
                count ++;
            
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
            res.Add(sum/count);
        }
        return res.ToArray();
    }
}