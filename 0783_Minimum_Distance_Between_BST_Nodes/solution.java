package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.List;

/*
783. Minimum Distance Between BST Nodes


Given a Binary Search Tree (BST) with the root node root, return the minimum difference
between the values of any two different nodes in the tree.
 */
public class LC_0783_MinimumDistanceBetweenBSTNodes {
    public int minDiffInBST(TreeNode root) {
        if (root == null)
            return -1;
        int res = Integer.MAX_VALUE;
        List<Integer> values = new ArrayList<>();
        inorder(root, values);

        for (int i = 1; i < values.size(); i++) {
            res = Math.min(res, values.get(i) - values.get(i - 1));
        }
        return res;
    }

    void inorder(TreeNode node, List<Integer> vals) {
        if (node == null)
            return;
        inorder(node.left, vals);
        vals.add(node.val);
        inorder(node.right, vals);
    }

    private  int res = Integer.MAX_VALUE;
    int minDiffInBST_Better(TreeNode root) {

        helper(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
        return res;
    }
    void helper(TreeNode node, int low, int high) {
        if (node == null) return;
        if (low != Integer.MIN_VALUE) res = Math.min(res, node.val - low);
        if (high != Integer.MAX_VALUE) res = Math.min(res, high - node.val);
        helper(node.left, low, node.val);
        helper(node.right, node.val, high);
    }
}
