package cn.huang.leetcode;

/*
    606. Construct String from Binary Tree
 */

import cn.huang.leetcode.common.TreeNode;

public class LC_0606_ConstructStringfromBinaryTree {
    public String tree2str(TreeNode t) {
        if (t == null)
            return "";

        String res = t.val + "";
        if (t.left == null && t.right == null) {
            return res;
        }

        if (t.left != null) {
            res = res + "(" + tree2str(t.left) + ")";
            if (t.right != null) {
                res = res + "(" + tree2str(t.right) + ")";
            }
        } else {
            res = res + "()";
            if (t.right != null) {
                res = res + "(" + tree2str(t.right) + ")";
            }
        }
        return res;
    }
}
