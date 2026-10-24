package cn.huang.leetcode;
/*
    671. Second Minimum Node In a Binary Tree

    Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in
    this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the
    smaller value among its two sub-nodes.

    Given such a binary tree, you need to output the second minimum value in the set made of all the nodes'
    value in the whole tree.
 */

import cn.huang.leetcode.common.TreeNode;

import java.util.LinkedList;
import java.util.Queue;

public class LC_0671_SecondMinimumNodeInaBinaryTree {
    int min = Integer.MAX_VALUE;
    int secondMin = Integer.MAX_VALUE;
    boolean seenMoreThanOne = false;
    int orig = -1;

    public int findSecondMinimumValue(TreeNode root) {
        if (root == null)
            return -1;

        orig = root.val;
        preOrderWalk(root);
        if (min == secondMin || !seenMoreThanOne)
            return -1;
        return secondMin;
    }

    private void preOrderWalk(TreeNode root) {
        if (root == null)
            return;

        if (root.val != orig) {
            seenMoreThanOne = true;
        }
        if (root.val < min) {
            int tmp = min;
            min = root.val;
            secondMin = tmp;
        } else if (root.val < secondMin && root.val != min) {
            secondMin = root.val;
        }
        preOrderWalk(root.left);
        preOrderWalk(root.right);
    }

    public int findSecondMinimumValue_bfs(TreeNode root) {
        return bfs(root);
    }

    private int bfs(TreeNode root) {
        if (root == null)
            return -1;
        int smallest = root.val;
        int secondSmallest = Integer.MAX_VALUE;
        boolean found = false;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();

            if (node.val > smallest && node.val < secondSmallest) {
                secondSmallest = node.val;
                found = true;
                // No need to process node's children. because node.val > smallest, value of children > node.val > smallest
                continue;
            }

            if (node.left != null)
                queue.add(node.left);

            if (node.right != null)
                queue.add(node.right);
        }
        return found ? secondSmallest : -1;
    }

    public int findSecondMinimumValue_dfs(TreeNode root) {
        return dfs(root, root.val);
    }

    private int dfs(TreeNode root, int smallest) {
        if (root == null)
            return -1;
        // value node.val > smallest, value of children > node.val > smallest
        if (root.val > smallest)
            return root.val;
        int sl = dfs(root.left, smallest);
        int sr = dfs(root.right, smallest);

        if (sl == -1)
            return sr;

        if (sr == -1)
            return sl;

        return Math.min(sl, sr);
    }
}
