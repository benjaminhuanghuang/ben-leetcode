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
