package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*
106. Construct Binary Tree from Inorder and Postorder Traversal


 */
public class LC_0106_ConstructBinaryTreefromInorderandPostorderTraversal {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder == null || inorder.length < 1 || postorder == null || postorder.length < 1)
            return null;

        return helper(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1);
    }


    private TreeNode helper(int[] inorder, int inorderStart, int inorderEnd, int[] postorder, int postorderStart, int postorderEnd) {
        if (inorderStart > inorderEnd || postorderStart > postorderEnd) {
            return null;
        }
        if (inorderStart == inorderEnd || postorderStart == postorderEnd) {
            return new TreeNode(postorder[postorderEnd]);
        }

        TreeNode root = new TreeNode(postorder[postorderEnd]);

        // find root value in inroder[]
        for (int i = inorderStart; i <= inorderEnd; i++) {
            if (postorder[postorderEnd] == inorder[i]) {
                int leftCount = i - inorderStart;
                root.left = helper(inorder, inorderStart, i - 1, postorder, postorderStart, postorderStart + leftCount - 1);
                root.right = helper(inorder, i + 1, inorderEnd, postorder, postorderStart + (leftCount - 1) + 1, postorderEnd - 1);
            }
        }
        return root;
    }
}
