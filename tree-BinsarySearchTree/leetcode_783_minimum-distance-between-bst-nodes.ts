/*
783. Minimum Distance Between BST Nodes

https://leetcode.com/problems/minimum-distance-between-bst-nodes/
*/

import { TreeNode } from "../Common/TreeNode";

function minDiffInBST(root: TreeNode | null): number {
  let minDiff = Number.MAX_SAFE_INTEGER;
  let prev: number | null = null;

  function inorder(node: TreeNode | null) {
    if (node == null) return;

    inorder(node.left);

    if (prev != null) minDiff = Math.min(minDiff, node.val - prev);

    prev = node.val;

    inorder(node.right);
  }

  inorder(root);

  return minDiff;
}
