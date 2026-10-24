package cn.huang.leetcode;
/*
    100  Same Tree
 */

import cn.huang.leetcode.common.TreeNode;

public class LC_0100_SameTree {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null && q ==null)
            return true;

        if(p == null || q == null)
            return false;

        return p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}
