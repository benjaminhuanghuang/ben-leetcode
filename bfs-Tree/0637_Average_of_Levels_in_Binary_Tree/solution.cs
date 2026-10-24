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