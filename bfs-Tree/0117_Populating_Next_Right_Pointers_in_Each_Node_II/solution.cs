using System.Collections.Generic;

public class Solution117
{
    public class TreeLinkNode
    {
        int val;
        public TreeLinkNode left, right, next;
        TreeLinkNode(int x) { val = x; }
    }

    public void Connect(TreeLinkNode root)
    {
        var currLevel = new List<TreeLinkNode>();
        var nextLevel = new List<TreeLinkNode>();

        if (root != null)
        {
            currLevel.Add(root);
        }

        while (currLevel.Count > 0)
        {
            for (int i = 0; i < currLevel.Count - 1; i++)
            {
                var cur = currLevel[i];
                cur.next =  currLevel[i+1];
                if (cur.left != null)
                {
                    nextLevel.Add(cur.left);
                }
                if (cur.right != null)
                {
                    nextLevel.Add(cur.right);
                }
            }

            currLevel = nextLevel;
            nextLevel = new List<TreeLinkNode>(); 
        }
    }
}