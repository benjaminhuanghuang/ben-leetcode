package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.List;

/*
113. Path Sum II
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1

Return:

[
   [5,4,11,2],
   [5,8,4,5]
]


 */
public class LC_0113_PathSum_II {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res = new ArrayList<>();
        helper(root, sum, res, new ArrayList<Integer>());
        return res;
    }

    private void helper(TreeNode root, int sum, List<List<Integer>> res, List<Integer> combination) {
        if (root == null)
            return;

        if (root.left == null && root.right == null) {
            if (sum == root.val) {
                List<Integer> path = new ArrayList<>(combination);
                path.add(root.val);
                res.add(path);
            }
            return;
        }

        combination.add(root.val);
        helper(root.left, sum - root.val, res, combination);
        helper(root.right, sum - root.val, res, combination);
        combination.remove(combination.size() - 1);
    }
}
