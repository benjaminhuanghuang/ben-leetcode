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