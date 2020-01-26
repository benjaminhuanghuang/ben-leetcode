package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*
    538. Convert BST to Greater Tree
    Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed
    to the original key plus sum of all keys greater than the original key in BST.
 */
public class LC_0538_ConvertBSTtoGreaterTree {
    int sum = 0;
    public TreeNode convertBST(TreeNode root) {
        if(root == null)
            return null;

        // all keys greater than the original key are the right sub tree node
        convertBST(root.right);
        root.val += sum;
        sum = root.val;   // add the sum to left sub tree
        convertBST(root.left);
        return root;
    }


}
