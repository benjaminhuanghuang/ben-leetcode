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