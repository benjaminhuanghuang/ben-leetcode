package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*
    938. Range Sum of BST

    Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

    The binary search tree is guaranteed to have unique values.


 */
public class LC_0938_RangeSumofBST {
    public int rangeSumBST(TreeNode root, int L, int R) {
        if (root == null)
            return 0;

        if (root.val > R) {
            return rangeSumBST(root.left, L, R);
        }
        if(root.val < L)
        {
            return rangeSumBST(root.right, L,R);
        }
        else
        {
            return root.val;
        }
    }
}
