/*
117. Populating Next Right Pointers in Each Node II

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

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