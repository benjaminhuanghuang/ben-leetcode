package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*
156. Binary Tree Upside Down

Given a binary tree where all the right nodes are either leaf nodes with a sibling
(a left node that shares the same parent node) or empty, flip it upside down and
turn it into a tree where the original right nodes turned into left leaf nodes.
Return the new root.

For example:
Given a binary tree {1,2,3,4,5},
    1
   / \
  2   3
 / \
4   5
return the root of the binary tree [4,5,2,#,#,3,1].
   4
  / \
 5   2
    / \
   3   1
*/
public class LC_0156_BinaryTreeUpsideDown {
    /*
    新的root是原二叉树最左端节点。sibling变为新树左节点，原root变为新树右节点。
     */
    public TreeNode upsideDownBinaryTree(TreeNode root) {
        if (root == null || root.left == null)
            return root;

        TreeNode newRoot = upsideDownBinaryTree(root.left);
        root.left.left = root.right;
        root.left.right = root;
        root.left = null;
        root.right = null;
        return newRoot;
    }

    /*
        把左子树继续颠倒，颠倒完后，原来的那个左孩子的左右孩子指针分别指向原来的根节点以及原来的右兄弟节点即可。

     */
    public TreeNode UpsideDownBinaryTree2(TreeNode root) {
        if (root == null)
            return null;
        TreeNode parent = root, left = root.left, right = root.right;
        if (left != null) {
            TreeNode ret = UpsideDownBinaryTree2(left);
            left.left = right;
            left.right = parent;
            return ret;
        }
        return root;
    }


    public TreeNode upsideDownBinaryTree_iterator(TreeNode root) {
        if (root == null)
            return root;
        TreeNode left = null, right = null, prev = null;
        while (root != null) {
            left = root.left;
            root.left = right;
            right = root.right;
            root.right = prev;
            prev = root;
            root = left;
        }
        return prev;
    }
}
