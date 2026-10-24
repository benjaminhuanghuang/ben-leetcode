package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*
235. Lowest Common Ancestor of a Binary Search Tree
The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as
descendants (where we allow a node to be a descendant of itself).”

 */
public class LC_0235_LowestCommonAncestorofaBST {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode m = root;

        if (m.val > p.val && m.val < q.val) {
            return m;
        } else if (m.val > p.val && m.val > q.val) {
            return lowestCommonAncestor(root.left, p, q);
        } else if (m.val < p.val && m.val < q.val) {
            return lowestCommonAncestor(root.right, p, q);
        }

        return root;
    }
}
