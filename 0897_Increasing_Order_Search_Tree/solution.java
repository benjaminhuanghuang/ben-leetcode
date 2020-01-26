package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.List;

/*
    897	 Increasing Order Search Tree

    Given a tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree,
    and every node has no left child and only 1 right child.
 */
public class LC_0897_IncreasingOrderSearchTree {
    public TreeNode increasingBST(TreeNode root) {
        return traverse(root, null);
    }

    private TreeNode traverse (TreeNode root, TreeNode tail)
    {
        if (root == null)
            return null;

        TreeNode newRoot = root;
        if(root.right != null)
        {
            root.right = traverse(root.right, tail);
        }
        else
        {
            root.right = tail;
        }
        if(root.left != null)
        {
            newRoot = traverse(root.left, root);
            root.left = null;
        }
        return newRoot;
    }


    /*
        inorderTraversal -> List -> Tree

     */
    public List<TreeNode> list = new ArrayList<>();
    public TreeNode increasingBST_V1(TreeNode root) {
        inorderTraversal(root);

        if (list.size() == 0) return null;

        TreeNode ans = list.get(0);
        TreeNode curr = ans;

        for (int i=1; i<list.size(); i++) {
            curr.right = list.get(i);
            curr.left = null;
            curr = curr.right;
        }

        curr.left = null;

        return ans;
    }

    public void inorderTraversal(TreeNode root) {
        if (root == null) return;

        inorderTraversal(root.left);
        list.add(root);
        inorderTraversal(root.right);
    }
}
