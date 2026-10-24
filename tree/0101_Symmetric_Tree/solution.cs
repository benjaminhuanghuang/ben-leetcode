using System.Linq;
using System.Collections.Generic;

public class Solution101 {
    public bool IsSymmetric_Recursively(TreeNode root) {
        return root == null || this.isSymmetricRecursion(root.left, root.right);
    }

    private bool isSymmetricRecursion(TreeNode node1, TreeNode node2)
    {
        if (node1 == null && node2 == null)
        {
            return true;
        }
        else if(node1 == null || node2 == null)
        {
            return false;
        }

        if (node1.val != node2.val)
        {
            return false;
        }

        return this.isSymmetricRecursion(node1.left, node2.right)
                && this.isSymmetricRecursion(node1.right, node2.left);
    }

    public bool IsSymmetric(TreeNode root)
    {
        var cur = new Queue<TreeNode>();
        cur.Enqueue(root);
        var next = new Queue<TreeNode>();

        do
        {
            while (cur.Any())
            {
                var top = cur.Dequeue();

                if (top == null)
                {
                    continue;
                }

                next.Enqueue(top.left);
                next.Enqueue(top.right);
            }

            var nextList = next.ToList();
            if (!IsSymmetricList(nextList)) return false;

            while (next.Any())
            {
                cur.Enqueue(next.Dequeue());
            }
        }
        while (cur.Any());

        return true;
    }

    private bool IsSymmetricList(List<TreeNode> nextList)
    {
        for (int i = 0, j = nextList.Count - 1; i < j; i++, j--)
        {
            if (nextList[i] == null && nextList[j] == null)
            {
                continue;
            }
            else if(nextList[i] == null || nextList[j] == null)
            {
                return false;
            }

            if (nextList[i].val != nextList[j].val)
            {
                return false;
            }
        }

        return true;
    }
}