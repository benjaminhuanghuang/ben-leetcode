package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
515. Find Largest Value in Each Tree Row

 */
public class LC_0515_FindLargestValueinEachTreeRow {
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> res = new ArrayList<>();

        if (root == null)
            return res;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int max = Integer.MIN_VALUE;
            Queue<TreeNode> nextQ = new LinkedList<>();
            while (!q.isEmpty()) {
                TreeNode node = q.poll();
                int val = node.val;
                if (val > max) {
                    max = val;
                }
                if (node.left != null)
                    nextQ.add(node.left);
                if (node.right != null)
                    nextQ.add(node.right);
            }

            res.add(max);
            q = nextQ;
        }
        return res;
    }

    public List<Integer> largestValues_better(TreeNode root) {
        List<Integer> res = new ArrayList<>();

        if (root == null)
            return res;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int max = Integer.MIN_VALUE;
            int n = q.size();// pop the node in 1 layer
            for (int i = 0; i < n; ++i) {
                TreeNode node = q.poll();
                int val = node.val;
                if (val > max) {
                    max = val;
                }
                if (node.left != null)
                    q.add(node.left);
                if (node.right != null)
                    q.add(node.right);
            }

            res.add(max);
        }
        return res;
    }
}
