package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.Arrays;

/*
105. Construct Binary Tree from Preorder and Inorder Traversal

 */
public class LC_0105_ConstructBinaryTreefromPreorderandInorderTraversal {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder == null || preorder.length < 1 || inorder == null || inorder.length < 1)
            return null;

        return helper(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }

    private TreeNode helper(int[] preorder, int preorderStart, int preorderEnd, int[] inorder, int inorderStart, int inorderEnd) {
        if (inorderStart > inorderEnd || preorderStart > preorderEnd) {
            return null;
        }
        if (inorderStart == inorderEnd || preorderStart == preorderEnd) {
            return new TreeNode(preorder[preorderStart]);
        }

        TreeNode root = new TreeNode(preorder[preorderStart]);

        // find root value in inroder[]
        for (int i = inorderStart; i <= inorderEnd; i++) {
            if (preorder[preorderStart] == inorder[i]) {

                root.left = helper(preorder, preorderStart + 1, preorderStart + (i - inorderStart), inorder, inorderStart, i - 1);
                root.right = helper(preorder, preorderStart + (i - inorderStart) + 1, preorderEnd, inorder, i + 1, inorderEnd);
            }
        }
        return root;
    }
}
