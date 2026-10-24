/*
993. Cousins in Binary Tree

https://leetcode.com/problems/cousins-in-binary-tree/
*/

import { TreeNode } from "../Common/TreeNode";

function isCousins(root: TreeNode | null, x: number, y: number): boolean {
  let parentX: TreeNode | null = null;
  let parentY: TreeNode | null = null;
  let depthX: number = -1;
  let depthY: number = -1;

  function preorder(
    node: TreeNode | null,
    x: number,
    y: number,
    parent: TreeNode | null,
    depth: number
  ) {
    if (node == null) {
      return;
    }
    if (node.val == x) {
      parentX = parent;
      depthX = depth;
    } else if (node.val == y) {
      parentY = parent;
      depthY = depth;
    }
    preorder(node.left, x, y, node, depth + 1);
    preorder(node.right, x, y, node, depth + 1);
  }

  preorder(root, x, y, null, 0);

  // cousins
  return parentX != parentY && depthX == depthY;
}
