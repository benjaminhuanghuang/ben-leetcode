package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*
701. Insert into a Binary Search Tree


 */
public class LC_0701_InsertintoaBinarySearchTree {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null)
            return new TreeNode(val);

        TreeNode p = root;
        while (p != null) {
            if (val < p.val) {
                if (p.left == null) {
                    p.left = new TreeNode(val);
                    break;
                }
                p = p.left;
            } else {
                if (p.right == null) {
                    p.right = new TreeNode(val);
                    break;
                }
                p = p.right;
            }
        }
        return root;
    }

    public TreeNode insertIntoBST_Recursion(TreeNode root, int val) {
        if (root == null)
            return new TreeNode(val);

        TreeNode p = root;
        while (p != null) {
            if (val > p.val) {
                root.right = insertIntoBST(root.right, val);
            } else {
                root.left = insertIntoBST(root.left, val);
            }
        }
        return root;
    }
}
