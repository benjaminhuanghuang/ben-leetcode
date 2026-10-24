/*
95. Unique Binary Search Trees II

Given an integer n, generate all structurally unique BST's (binary search trees) that store 
values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
using System.Collections.Generic;

public class Solution095 {
    //http://www.programcreek.com/2014/05/leetcode-unique-binary-search-trees-ii-java/
    // Use dp[n] indicates the list of BST store values from 1 to i.
    public IList<TreeNode> GenerateTrees(int n) {
        if (n ==0)
            return new List<TreeNode>();
        var result = this.BuildTree(1, n);
        return result; 
    }

    private List<TreeNode> BuildTree(int start, int end)
    {
        var result = new List<TreeNode>();
        if (start > end)
        {
            result.Add(null);   // Important
            return result;
        }
        for (int rootValue = start; rootValue <= end; rootValue++)
        {
            List<TreeNode> leftTrees = this.BuildTree(start, rootValue - 1);
            List<TreeNode> rightTrees = this.BuildTree(rootValue + 1, end);
            foreach (var lTree in leftTrees)
            {
                foreach (var rTree in rightTrees)
                {
                    TreeNode root = new TreeNode(rootValue);
                    root.left = lTree;
                    root.right = rTree;
                    result.Add(root);
                }
            }
        }
        return result;
    }
}