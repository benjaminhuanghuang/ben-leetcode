package cn.huang.leetcode;
/*
124. Binary Tree Maximum Path Sum

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree
along the parent-child connections. The path must contain at least one node and does not need to go through
the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6

Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42


 */


import cn.huang.leetcode.common.TreeNode;

/*
//最大的路径和:
// 1 是左子树的路径加上当前节点，
// 2 右子树的路径加上当前节点，
// 3 左右子树的路径加上当前节点（相当于一条横跨当前节点的路径），
// 4 只有自己的路径。
 */
public class LC_0124_BinaryTreeMaximumPathSum {
    private long res = Integer.MIN_VALUE;

    public int maxPathSum(TreeNode root) {
        helper(root);
        return (int) res;
    }

    private int helper(TreeNode root) {
        if (root == null)
            return 0;

        int left = helper(root.left);
        int right = helper(root.right);
        // case: 1,2,4
        int currSum = Math.max(Math.max(left, right) + root.val, root.val);
        // case: 1,2,3,4
        res = Math.max(res, Math.max(currSum, left + right + root.val));
        return currSum;
    }
}
