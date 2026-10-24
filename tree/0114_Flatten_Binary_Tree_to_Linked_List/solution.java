package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.ArrayList;
import java.util.List;

/*

114. Flatten Binary Tree to Linked List

Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6

The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6


 */

/*
each node’s right child points to the next node of a pre-order traversal.
每一个节点的右孩子都是其先序遍历的下一个节点。

 */
public class LC_0114_FlattenBinaryTreetoLinkedList {
    public void flatten(TreeNode root) {
        List<TreeNode> nodes = new ArrayList<TreeNode>();
        this.preOrder(root, nodes);

        TreeNode start = root;
        for (int i = 1; i < nodes.size(); i++) {
            start.right = nodes.get(i);
            start.left = null;

            start = start.right;
        }
    }

    private void preOrder(TreeNode root, List<TreeNode> nodes) {
        if (root == null) return;
        // visited root
        nodes.add(root);

        this.preOrder(root.left, nodes);
        this.preOrder(root.right, nodes);
    }
}
