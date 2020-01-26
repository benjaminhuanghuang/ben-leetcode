package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.*;

/*
 314. Binary Tree Vertical Order Traversal

Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7



return its vertical order traversal as:

[
  [9],
  [3,15],
  [20],
  [7]
]



Given binary tree [3,9,20,4,5,2,7],

    _3_
   /   \
  9    20
 / \   / \
4   5 2   7



return its vertical order traversal as:

[
  [4],
  [9],
  [3,5,2],
  [20],
  [7]
]

 */


public class LC_0314_BinaryTreeVerticalOrderTraversal {
    /*
    https://www.youtube.com/watch?v=KrT_qcGj4nA

     */
    // 以root为对称轴，左右各多少node，最终结果就有几个list
    private int min = 0;
    private int max = 0;

    public List<List<Integer>> verticalOrder_dfs(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (root == null)
            return result;

        helper(root, 0);

        for (int i = min; i <= max; i++) {
            result.add(new ArrayList<>());
        }

        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        Queue<Integer> indexes = new LinkedList<Integer>();

        queue.offer(root);
        indexes.offer(-min);  // root所在的index

        while (!queue.isEmpty()) {
            TreeNode curr = queue.poll();
            int index = indexes.poll();

            result.get(index).add(curr.val);
            if (curr.left != null) {
                queue.offer(curr.left);
                indexes.offer(index - 1);
            }
            if (curr.right != null) {
                queue.offer(curr.right);
                indexes.offer(index + 1);
            }
        }

        return result;
    }

    private void helper(TreeNode root, int index) {
        if (root == null)
            return;

        min = Math.min(min, index);
        max = Math.max(max, index);

        helper(root.left, index - 1);
        helper(root.right, index + 1);
    }


    public List<List<Integer>> verticalOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (root == null)
            return result;

        // level and list
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<Integer, ArrayList<Integer>>();

        LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
        LinkedList<Integer> level = new LinkedList<Integer>();

        queue.offer(root);
        level.offer(0);

        int minLevel = 0;
        int maxLevel = 0;

        while (!queue.isEmpty()) {
            TreeNode p = queue.poll();
            int l = level.poll();

            //track min and max levels
            minLevel = Math.min(minLevel, l);
            maxLevel = Math.max(maxLevel, l);

            if (map.containsKey(l)) {
                map.get(l).add(p.val);
            } else {
                ArrayList<Integer> list = new ArrayList<Integer>();
                list.add(p.val);
                map.put(l, list);
            }

            if (p.left != null) {
                queue.offer(p.left);
                level.offer(l - 1);
            }

            if (p.right != null) {
                queue.offer(p.right);
                level.offer(l + 1);
            }
        }


        for (int i = minLevel; i <= maxLevel; i++) {
            if (map.containsKey(i)) {
                result.add(map.get(i));
            }
        }

        return result;
    }
}
