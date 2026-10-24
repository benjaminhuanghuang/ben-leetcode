package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.List;

/*
530. Minimum Absolute Difference in BST
 */
public class LC_0530_MinimumAbsoluteDifferenceinBST {
    List<Integer> nodes = new ArrayList<Integer>();

    public int getMinimumDifference(TreeNode root) {

        triversal(root);
        int result = Integer.MAX_VALUE;
        for (int i = 1; i < nodes.size(); i++) {
            if (nodes.get(i) - nodes.get(i - 1) < result)
                result = nodes.get(i) - nodes.get(i - 1);
        }
        return result;

    }

    public void triversal(TreeNode root) {
        if (root != null) {
            triversal(root.left);
            nodes.add(root.val);
            triversal(root.right);
        }
    }

    int min = Integer.MAX_VALUE;
    Integer prev = null;
    public int getMinimumDifference_Faster(TreeNode root) {
        if (root == null) return min;

        getMinimumDifference(root.left);

        if (prev != null) {
            min = Math.min(min, root.val - prev);
        }
        prev = root.val;

        getMinimumDifference(root.right);

        return min;
    }
}
