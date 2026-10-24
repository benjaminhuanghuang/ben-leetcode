/*
145. Binary Tree Postorder Traversal
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

*/
using System.Collections.Generic;

public class Solution145 {
    // similar to the pre-order traversal. Remember to reverse the result.
    public IList<int> PostorderTraversal_Iterative(TreeNode root) {
        var res = new List<int>();
        var nodeStack = new Stack<TreeNode>();
        if (root != null)
            nodeStack.Push(root);
        while (nodeStack.Count > 0)
        {
            var top = nodeStack.Pop();
            res.Add(top.val);

            // Note! push left firstly
            if (top.left != null)
            {
                nodeStack.Push(top.left);
            }
            if (top.right != null)
            {
                nodeStack.Push(top.right);
            }
        }
        res.Reverse();
        return res;
    }
    public IList<int> PostorderTraversal_Iterative_Morris(TreeNode root) {
        var res = new List<int>();
        while (root != null)
        {
            if (root.left != null)
            {
                var pre = root.left;
                while (pre.right != null && pre.right != root)
                {
                    pre = pre.right;
                }

                if (pre.right == null)
                {
                    pre.right = root;
                    root = root.left;
                }
                else
                {
                    pre.right = null;
                    root = root.right;
                }
            }
            else
            {
                root = root.right;
            }
        }

        return res;
    }
}