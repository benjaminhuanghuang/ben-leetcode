/*
124. Binary Tree Maximum Path Sum

Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any 
node in the tree along the parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3


Return 6.
*/
using System;

//最大的路径和:
// 1 是左子树的路径加上当前节点，
// 2 右子树的路径加上当前节点，
// 3 左右子树的路径加上当前节点（相当于一条横跨当前节点的路径），
// 4 只有自己的路径。
public class Solution124 {
    private long res = int.MinValue;
    
    public int maxPathSum(TreeNode root) {
    {
        MaxPathSumHelper(root);
        return (int)res;
    }

    private long MaxPathSumHelper(TreeNode root)
    {
        if (root == null) 
            return 0;

        var left = MaxPathSumHelper(root.left);
        var right = MaxPathSumHelper(root.right);
        // case: 1,2,4
        var currSum = Math.Max(Math.Max(left, right) + root.val, root.val);
        // case: 1,2,3,4
        res = Math.Max(res, Math.Max(currSum, left + right + root.val));
        return currSum;
    }
}