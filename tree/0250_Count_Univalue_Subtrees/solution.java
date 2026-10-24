package cn.huang.leetcode;
/*
250. Count Univalue Subtrees

Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,

              5
             / \
            1   5
           / \   \
          5   5   5


return 4.
 */


import cn.huang.leetcode.common.TreeNode;

public class LC_0250_CountUnivalueSubtrees {
    int res = 0;

    int countUnivalSubtrees(TreeNode root) {
        if (root == null)
            return res;
        if (isUnival(root, root.val))
            ++res;
        countUnivalSubtrees(root.left);
        countUnivalSubtrees(root.right);
        return res;
    }

    boolean isUnival(TreeNode root, int val) {
        if (root == null)
            return true;
        return root.val == val && isUnival(root.left, val) && isUnival(root.right, val);
    }
}
