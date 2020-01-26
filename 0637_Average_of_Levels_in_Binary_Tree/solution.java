package cn.huang.leetcode;
/*
 637. Average of Levels in Binary Tree
 */

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class LC_0637_AverageofLevelsinBinaryTree {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> res = new ArrayList<Double>();
        if (root == null) {
            return res;
        }

        LinkedList<TreeNode> que = new LinkedList<TreeNode>();
        que.add(root);

        while (!que.isEmpty()) {
            int count = que.size();
            double sum = 0.0;
            for (int i = 0; i < count; i++) {
                TreeNode tn = que.poll();
                sum += tn.val;
                if (tn.left != null) {
                    que.add(tn.left);
                }
                if (tn.right != null) {
                    que.add(tn.right);
                }
            }
            res.add(sum / count);
        }
        return res;
    }
}
