package cn.huang.leetcode;
/*
    700. Search in a Binary Search Tree
 */
import cn.huang.leetcode.common.TreeNode;

public class LC_0700_SearchinaBinarySearchTree {
    public TreeNode searchBST(TreeNode root, int val) {
        if(root == null)
            return null;

        if(root.val == val)
            return root;
        else if(root.val > val)
            return searchBST(root.left, val);
        else
            return searchBST(root.right, val);
    }


}
