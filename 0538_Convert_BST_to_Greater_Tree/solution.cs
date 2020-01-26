/*
538. Convert BST to Greater Tree
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original 
BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
 */
using System;
using System.Collections.Generic;

 public class Solution538 {
    List<TreeNode> treeList = new List<TreeNode>();
    public TreeNode ConvertBST(TreeNode root) {
        if(root == null || root.left == null && root.right == null){
            return root;
        }
        goThrough(root);

        int len = treeList.Count;
        int sumOfGreater = treeList[len - 1].val; // sum of value greater than current element

        for(int i = len - 2; i >= 0; i--){
            int val = treeList[i].val;
            treeList[i].val += sumOfGreater;
            sumOfGreater += val;
        }

        return root;
    }

    private void goThrough(TreeNode root){
        if(root.left != null){
            goThrough(root.left);
        }
        treeList.Add(root);
        if(root.right != null){
            goThrough(root.right);
        }
    }
}
