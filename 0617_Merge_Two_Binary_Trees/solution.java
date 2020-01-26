package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*
    617. Merge Two Binary Trees
    Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees
    are overlapped while the others are not.

    You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up
    as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.
 */
public class LC_0617_MergeTwoBinaryTrees {
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null)
            return null;
        if (t1 == null)
            return t2;
        if (t2 == null)
            return t1;

        t1.val += t2.val;
        t1.left = mergeTrees(t1.left, t2.left);
        t1.right = mergeTrees(t1.right, t2.right);

        return t1;
    }
}
