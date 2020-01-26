package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*
    226. Invert Binary

    Invert a binary tree.

    Example:

    Input:

         4
       /   \
      2     7
     / \   / \
    1   3 6   9

    Output:

         4
       /   \
      7     2
     / \   / \
    9   6 3   1

    Trivia:
    This problem was inspired by this original tweet by Max Howell:

        Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.


 */
public class LC_0226_InvertBinaryTree {
    public TreeNode invertTree(TreeNode root) {
        if(root == null)
            return root;

        TreeNode tmp = invertTree(root.right);
        root.right = invertTree(root.left);
        root.left = tmp;

        return root;
    }
}
