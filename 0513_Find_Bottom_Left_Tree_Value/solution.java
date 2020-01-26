package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.LinkedList;
import java.util.Queue;

/*
513. Find Bottom Left Tree Value

 Given a binary tree, find the leftmost value in the last row of the tree.
 */
public class LC_0513_FindBottomLeftTreeValue {
    public int findBottomLeftValue(TreeNode root) {
        if (root == null) return 0;
        int res = 0;
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        while (!q.isEmpty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode t = q.poll();
                if (i == 0)
                    res = t.val;
                if (t.left != null) q.add(t.left);
                if (t.right != null) q.add(t.right);
            }
        }
        return res;
    }
}
