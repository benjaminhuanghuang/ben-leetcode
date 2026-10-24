/*
105. Construct Binary Tree from Preorder and Inorder Traversal

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

*/
using System;
using System.Collections;

public class Solution105 {
    public TreeNode BuildTree(int[] preorder, int[] inorder) {
        if (inorder.Length == 0 || preorder.Length == 0) 
            return null;
            
        return BuildTreeRecursion(inorder, 0, inorder.Length - 1, preorder, 0, preorder.Length - 1);
    }

    // The first element in the preorder traversal is the root, 
    // find it in inorder traversal, left part is the left children, right part is the right children.
    private TreeNode BuildTreeRecursion(int[] inorder, int inorderStart, int inorderEnd, int[] preorder, int preorderStart, int preorderEnd)
    {
        if (inorderStart > inorderEnd || preorderStart > preorderEnd)
        {
            return null;
        }
        if (inorderStart == inorderEnd || preorderStart == preorderEnd)
        {
            return new TreeNode(preorder[preorderEnd]);
        }

        var root = new TreeNode(preorder[preorderStart]);

        var rootIndex = Array.IndexOf(inorder, preorder[preorderStart], inorderStart, inorderEnd - inorderStart + 1);
        var leftCount = rootIndex - inorderStart;
        var rightCount = inorderEnd - rootIndex;
        var left = BuildTreeRecursion(inorder, inorderStart, rootIndex - 1, preorder, preorderStart + 1, preorderStart + leftCount);
        var right = BuildTreeRecursion(inorder, rootIndex + 1, inorderEnd, preorder, preorderEnd - rightCount + 1, preorderEnd);

        root.left = left;
        root.right = right;

        return root;
    }
}