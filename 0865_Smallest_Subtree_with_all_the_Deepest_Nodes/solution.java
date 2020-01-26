package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

/*
865. Smallest Subtree with all the Deepest Nodes

Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.

A node is deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is that node, plus the set of all descendants of that node.

Return the node with the largest depth such that it contains all the deepest nodes in its subtree.
 */
public class LC_0865_SmallestSubtreewithalltheDeepestNodes {
    class Result {
        int depth;
        TreeNode node;

        public Result(TreeNode node, int depth) {
            this.depth = depth;
            this.node = node;
        }
    }
    /*
       Case 1: depth left = depth right, return root
       Case 1: depth left > depth right, return answer of root->left
     */
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        TreeNode result = null;
        return depth(root).node;
    }

    private Result depth(TreeNode root) {
        if (root == null)
            return new Result(null, 0);
        Result left = depth(root.left);
        Result right = depth(root.right);
        if (left.depth == right.depth)
            return new Result(root, left.depth + 1);
        else if (left.depth > right.depth)
            return new Result(left.node, left.depth + 1);
        else
            return new Result(right.node, right.depth + 1);
    }
}
