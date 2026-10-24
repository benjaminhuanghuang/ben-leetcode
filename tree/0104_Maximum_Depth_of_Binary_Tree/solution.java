package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*
    104. Maximum Depth of Binary Tree
    Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.


 */
public class LC_0104_MaximumDepthofBinaryTree {
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        if (root.left == null && root.right == null)
            return 1;

        return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
    }
}
