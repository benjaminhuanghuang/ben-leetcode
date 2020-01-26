package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*
    404. Sum of Left Leaves
 */
public class LC_0404_SumofLeftLeaves {
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null)
            return 0;

        int sum = 0;
        if (root.left!= null && root.left.left == null && root.left.right == null)
            sum += root.left.val;
        else
        {
            sum += sumOfLeftLeaves(root.left);
        }
        sum += sumOfLeftLeaves(root.right);
        return sum;
    }
}
