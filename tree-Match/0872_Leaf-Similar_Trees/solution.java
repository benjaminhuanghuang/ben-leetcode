package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.List;

/*
    872	 Leaf-Similar Trees

 */
public class LC_0872_LeafSimilarTrees {
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        if(root1 == null && root2==null)
            return true;

        if(root1 == null || root2==null)
            return false;

        ArrayList<Integer> leaves1  = new ArrayList<>();
        ArrayList<Integer> leaves2  = new ArrayList<>();

        inOrder(root1, leaves1);
        inOrder(root2, leaves2);

        return leaves1.equals(leaves2);
    }

    private void inOrder(TreeNode root, ArrayList<Integer> leaves)
    {
        if(root == null)
            return;

        this.inOrder(root.left, leaves);
        if(root.left == null && root.right== null)
        {
            leaves.add(root.val);
        }
        this.inOrder(root.right, leaves);
    }
}
