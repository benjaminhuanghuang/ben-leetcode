package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.List;

/*
971. Flip Binary Tree To Match Preorder Traversal

Given a binary tree with N nodes, each node has a different value from {1, ..., N}.

A node in this binary tree can be flipped by swapping the left child and the right child of that node.

Consider the sequence of N values reported by a preorder traversal starting from the root.
Call such a sequence of N values the voyage of the tree.

(Recall that a preorder traversal of a node means we report the current node's value, then preorder-traverse the
left child, then preorder-traverse the right child.)

Our goal is to flip the least number of nodes in the tree so that the voyage of the tree matches the voyage we are given.

If we can do so, then return a list of the values of all nodes flipped.  You may return the answer in any order.

If we cannot do so, then return the list [-1].



Example 1:

Input: root = [1,2], voyage = [2,1]
Output: [-1]

Example 2:

Input: root = [1,2,3], voyage = [1,3,2]
Output: [1]

Example 3:

Input: root = [1,2,3], voyage = [1,2,3]
Output: []



Note:

    1 <= N <= 100


 */


/*
https://blog.csdn.net/fuxuemingzhu/article/details/85939252
 */
public class LC_0971_FlipBinaryTreeToMatchPreorderTraversal {
    int i = 0;
    List<Integer> res = new ArrayList<>();

    public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
        if (dfs(root, voyage)) {
            return res;
        }

        List<Integer> res2 = new ArrayList<Integer>();
        res2.add(-1);
        return res2;
    }

    // can we get v by flip root?
    boolean dfs(TreeNode root, int[] v) {
        if (root == null) return true;
        if (root.val != v[i++])
            return false;
        if (root.left != null && root.left.val == v[i]) {
            return dfs(root.left, v) && dfs(root.right, v);
        } else if (root.right != null && root.right.val == v[i]) {
            if (root.left != null)
                res.add(root.val);
            return dfs(root.right, v) && dfs(root.left, v);
        }
        return root.left == null && root.right == null;
    }
}
