package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*
	687	 Longest Univalue Path
	Given a binary tree, find the length of the longest path where each node in the path has the same value.
	This path may or may not pass through the root.

    Note: The length of path between two nodes is represented by the number of edges between them.



 */
public class LC_0687_LongestUnivaluePath {
    int length = 0;

    public int longestUnivaluePath(TreeNode root) {
        if (root == null)
            return 0;

        univaluePath(root);

        return length;
    }

    private int univaluePath(TreeNode root) {
        if (root == null)
            return 0;
        int leftLength = univaluePath(root.left);
        int rightLength = univaluePath(root.right);

        int left = 0;
        int right = 0;
        if (root.left != null && root.left.val == root.val) {
            left = leftLength + 1;
        }
        if (root.right != null && root.right.val == root.val) {
            right = rightLength + 1;
        }
        length = Math.max(length, left + right);
        return Math.max(left, right);
    }
}
