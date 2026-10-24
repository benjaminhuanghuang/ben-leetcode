using System;

public class Solution270 {
    public int closestValue(TreeNode root, double target) {
        // 选出子树的根节点
        TreeNode pivot = target < root.val ? root.left : root.right;
        // 如果没有子树，也就是递归到底时，直接返回当前节点值
        if(pivot == null) 
            return root.val;
        // 找出子树中最近的那个节点
        int closest = closestValue(pivot, target);
        // 返回根节点和子树最近节点中，更近的那个节点
        return Math.Abs(root.val - target) < Math.Abs(closest - target) ? root.val : closest;
    }
} 