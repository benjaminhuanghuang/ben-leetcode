package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.List;

import static java.lang.System.in;

/*
95. Unique Binary Search Trees II

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

 */
public class LC_0095_UniqueBinarySearchTrees_II {

    public List<TreeNode> generateTrees(int n) {
        if (n == 0)
            return new ArrayList<TreeNode>();
        List<TreeNode> result = this.BuildTree(1, n);
        return result;
    }

    private List<TreeNode> BuildTree(int start, int end) {
        List<TreeNode> result = new ArrayList<TreeNode>();
        if (start > end) {
            result.add(null);   // Important
            return result;
        }
        for (int rootValue = start; rootValue <= end; rootValue++) {
            List<TreeNode> leftTrees = this.BuildTree(start, rootValue - 1);
            List<TreeNode> rightTrees = this.BuildTree(rootValue + 1, end);
            for (TreeNode lTree : leftTrees) {
                for (TreeNode rTree : rightTrees) {
                    TreeNode root = new TreeNode(rootValue);
                    root.left = lTree;
                    root.right = rTree;
                    result.add(root);
                }
            }
        }
        return result;
    }
}
