/*
144. Binary Tree Preorder Traversal

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/
using System.Collections.Generic;

public class Solution144 {
    public IList<int> PreorderTraversal_Recursive(TreeNode root) {
        List<int> res = new List<int>();
        this.PreorderTraversal_Recursive_Helper(res, root);
        return res;
    }
    private void PreorderTraversal_Recursive_Helper(List<int> res, TreeNode root)
    {
        if (root == null)
            return;
        res.Add(root.val);
        PreorderTraversal_Recursive_Helper(res, root.left);
        PreorderTraversal_Recursive_Helper(res, root.right);
    }

    public IList<int> PreorderTraversal_Iterative(TreeNode root) {
        var values = new List<int>();
        var mystack = new Stack<TreeNode>();
        if (root != null)
        {
            mystack.Push(root);
        }

        while (mystack.Count > 0)
        {
            var top = mystack.Pop();
            values.Add(top.val);
            
            // Note! push right firstly.
            if (top.right != null)
            {
                mystack.Push(top.right);
            }
            if (top.left != null)
            {
                mystack.Push(top.left);
            }
        }

        return values;
    }
    // https://miafish.wordpress.com/2015/01/28/leetcode-oj-c-binary-tree-preorder-traversal/
    public IList<int> PreorderTraversal_Iterative_Morris(TreeNode root) 
    {
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
                    res.Add(root.val);
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
                res.Add(root.val);
                root = root.right;
            }
        }

        return res;     
    }

}