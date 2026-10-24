/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */

using System.Collections.Generic;

public class Solution094 {
    public IList<int> InorderTraversal_Recursion(TreeNode root) {
        List<int> result = new List<int>();
        this.InorderTraversalHelper(root, result);
        return result;
    }
    private void InorderTraversalHelper(TreeNode root, IList<int> result)
    {
        if (root != null)
        {
            InorderTraversalHelper(root.left, result);
            result.Add(root.val);
            InorderTraversalHelper(root.right, result);
        }
    }

    // 1. find the left most node without left child
    // 2. visit it
    // 3. if it has right child, find the left most node of its left child
    // 4. visit it
    // 5. go back to step 3
    public IList<int> InorderTraversal(TreeNode root)
    {
        var res = new List<int>();
        var mystack = new Stack<TreeNode>();
        findMostLeftNode(root, mystack);

        while (mystack.Count > 0)
        {
            var top = mystack.Pop();
            res.Add(top.val);

            findMostLeftNode(top.right, mystack);
        }

        return res;
    }

    private void findMostLeftNode(TreeNode root, Stack<TreeNode> mystack)
    {
        while (root != null)
        {
            mystack.Push(root);
            root = root.left;
        }
    }
    public IList<int> InorderTraversal_Iteratively(TreeNode root)
    {
        Stack<TreeNode> stack = new Stack<TreeNode>();
        var result = new List<int>();
        TreeNode curt = root;
        while (curt != null || stack.Count>0) {
            while (curt != null) {
                stack.Push(curt);
                curt = curt.left;
            }
            curt = stack.Pop();
            result.Add(curt.val);
            curt = curt.right;
        }
        return result;
    }
    //http://blog.csdn.net/linhuanmars/article/details/20187257
    public IList<int> InorderTraversal_Morris(TreeNode root)
    {
        var res = new List<int>();
        while (root != null)
        {
            if (root.left == null)
            {
                res.Add(root.val);
                root = root.right;
            }
            else
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
                    res.Add(root.val);
                    root = root.right;
                }
            }

        }

        return res;
    }
}
