package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.LinkedList;

/*
    101	Symmetric Tree
 */
public class LC_0101_SymmetricTree {
    public boolean isSymmetric_recursively(TreeNode root) {
        if (root == null)
            return true;

        return isMirror(root.left, root.right);
    }

    private boolean isMirror(TreeNode l, TreeNode r) {
        if (l == null && r == null)
            return true;
        else if (l != null && r != null && l.val == r.val)
            return isMirror(l.right, r.left) && isMirror(l.left, r.right);
        return false;
    }

    public boolean isSymmetric_iteratively(TreeNode root) {
        if (root == null)
            return true;

        if (root.left == null && root.right == null)
            return true;
        if (root.left == null || root.right == null)
            return false;

        LinkedList<TreeNode> q1 = new LinkedList<TreeNode>();
        LinkedList<TreeNode> q2 = new LinkedList<TreeNode>();
        q1.add(root.left);
        q2.add(root.right);

        while (!q1.isEmpty() && !q2.isEmpty()) {
            //retrieves and removes the head (first element) of this list
            TreeNode n1 = q1.poll();
            TreeNode n2 = q2.poll();

            if (n1.val != n2.val)
                return false;
            if ((n1.left == null && n2.right != null) || (n1.left != null && n2.right == null))
                return false;
            if ((n1.right == null && n2.left != null) || (n1.right != null && n2.left == null))
                return false;

            if (n1.left != null && n2.right != null) {
                q1.add(n1.left);
                q2.add(n2.right);
            }

            if (n1.right != null && n2.left != null) {
                q1.add(n1.right);
                q2.add(n2.left);
            }
        }
        return true;
    }
}
