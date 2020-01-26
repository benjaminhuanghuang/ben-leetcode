package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*
    563. Binary Tree Tilt
 */
public class LC_0563_BinaryTreeTilt {
    int sum = 0;

    public int findTilt(TreeNode root) {
        if(root == null)
            return 0;
        helper(root);

        return sum;
    }

    private int helper(TreeNode root){
        if(root == null)
            return 0;

        int left = helper(root.left);
        int right = helper(root.right);
        this.sum += Math.abs(left - right);
        return root.val + left + right;
    }

}
