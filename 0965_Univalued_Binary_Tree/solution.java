package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*
965. Univalued Binary Tree

 */
public class LC_0965_UnivaluedBinaryTree {
    public boolean isUnivalTree(TreeNode root) {
        if (root == null)
            return true;

        return helper(root.left, root.val) && helper(root.right, root.val);
    }

    private boolean helper(TreeNode node, int val) {
        if (node == null)
            return true;

        if (node.val == val) {
            return helper(node.left, val) && helper(node.right, val);
        }

        return false;
    }
}
