/*
106. Construct Binary Tree from Inorder and Postorder Traversal
Given inorder and postorder traversal of a tree, construct the binary tree.

*/
using System;

public class Solution106 {
    public TreeNode BuildTree(int[] inorder, int[] postorder)
    {
        if (inorder.Length == 0 || postorder.Length == 0) return null;

        return this.buildTreeRecursion(inorder, 0, inorder.Length - 1, postorder, 0, postorder.Length - 1);
    }

    private TreeNode buildTreeRecursion(int[] inorder, int inorderlow, int inorderhigh, 
                                        int[] postorder,int postorderlow, int postorderhigh)
    {
        if (inorderlow > inorderhigh || postorderlow > postorderhigh)
        {
            return null;
        }

        var rootValue = postorder[postorderhigh];
        var root = new TreeNode(rootValue);

        var inorderIndex = Array.IndexOf(inorder, postorder[postorderhigh], inorderlow, inorderhigh - inorderlow + 1);

        var leftCount = inorderIndex - inorderlow;
      
        root.left = this.buildTreeRecursion(inorder, inorderlow, inorderIndex - 1,
                                            postorder, postorderlow, postorderlow + leftCount - 1);

        root.right = this.buildTreeRecursion(inorder, inorderIndex + 1, inorderhigh,
                                            postorder, postorderlow + (leftCount - 1) + 1, postorderhigh - 1);

        return root;
    }
}