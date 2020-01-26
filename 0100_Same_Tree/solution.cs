/*
100. Same Tree
# 572
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/

public class Solution100 {
    public bool IsSameTree(TreeNode p, TreeNode q) {
        if ((p == null && q!=null) || (p != null && q==null))
            return false;
        if (p ==null && q == null)
            return true;
        if (p.val == q.val)
        {
            return IsSameTree(p.left, q.left) && IsSameTree(p.right, q.right);
        } 
        else
        {
            return false;
        }
    }

    public bool isSameTree_2(TreeNode p, TreeNode q)
    {
        if (p == null && q == null)
        {
            return true;
        }
        if (p == null || q == null)
        {
            return false;
        }

        if (p.val != q.val)
        {
            return false;
        }

        return this.isSameTree_2(p.left, q.left) && this.isSameTree_2(p.right, q.right);
    }
}