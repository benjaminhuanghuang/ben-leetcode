/*
Determine if a binary tree is height-balanced, meaning no node's left subtree and right
subtree have a height difference greater than 1.

*/

import { TreeNode } from "./tree";

function balancedBinaryTreeValidation(root: TreeNode | null): boolean {
  return getHeightImbalance(root) !== -1;
}

function getHeightImbalance(node: TreeNode | null): number {
  // Base case: empty node has height 0
  if (node === null) {
    return 0;
  }

  // Recursively compute left and right subtree heights
  const leftHeight = getHeightImbalance(node.left);
  const rightHeight = getHeightImbalance(node.right);

  // If any subtree is already imbalanced, propagate -1 upward
  if (leftHeight === -1 || rightHeight === -1) {
    return -1;
  }

  // If current node is imbalanced (height difference > 1)
  if (Math.abs(leftHeight - rightHeight) > 1) {
    return -1;
  }

  // Otherwise, return the height of the current subtree
  return Math.max(leftHeight, rightHeight) + 1;
}
