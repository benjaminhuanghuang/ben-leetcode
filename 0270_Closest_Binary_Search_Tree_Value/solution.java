package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*
	270	 Closest Binary Search Tree Value
	Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
 */
public class LC_0270_ClosestBinarySearchTreeValue {
    //https://www.youtube.com/watch?v=s7QcJi1qGEM
    public int closestValue_prefect(TreeNode root, double target) {
        int res = root.val;

        while (root != null) {
            if (Math.abs(target - root.val) < Math.abs(target - res)) {
                res = root.val;
            }
            root = root.val > target ? root.left : root.right;
        }
        return res;
    }

    int goal;
    double min = Double.MAX_VALUE;

    public int closestValue_Recursion(TreeNode root, double target) {
        helper(root, target);
        return goal;
    }

    public void helper(TreeNode root, double target) {
        if (root == null)
            return;

        if (Math.abs(root.val - target) < min) {
            min = Math.abs(root.val - target);
            goal = root.val;
        }

        if (target < root.val) {
            helper(root.left, target);
        } else {
            helper(root.right, target);
        }
    }

    public int closestValue_Iteration(TreeNode root, double target) {
        double min = Double.MAX_VALUE;
        int result = root.val;

        while (root != null) {
            if (target > root.val) {

                double diff = Math.abs(root.val - target);
                if (diff < min) {
                    min = Math.min(min, diff);
                    result = root.val;
                }
                root = root.right;
            } else if (target < root.val) {

                double diff = Math.abs(root.val - target);
                if (diff < min) {
                    min = Math.min(min, diff);
                    result = root.val;
                }
                root = root.left;
            } else {
                return root.val;
            }
        }

        return result;
    }

    public int closestValue_better(TreeNode root, double target) {
        // 选出子树的根节点
        TreeNode pivot = target < root.val ? root.left : root.right;
        // 如果没有子树，也就是递归到底时，直接返回当前节点值
        if (pivot == null)
            return root.val;
        // 找出子树中最近的那个节点
        int closest = closestValue_better(pivot, target);
        // 返回根节点和子树最近节点中，更近的那个节点
        return Math.abs(root.val - target) < Math.abs(closest - target) ? root.val : closest;
    }


}
