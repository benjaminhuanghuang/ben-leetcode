/*
114. Flatten Binary Tree to Linked List

https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

426. Convert Binary Search Tree to Sorted Doubly Linked List
*/

import { TreeNode } from "../Common/TreeNode";

function flatten(root: TreeNode | null): void {
  if (root === null) {
    return;
  }

  flatten(root.left);
  flatten(root.right);

  let left = root.left;
  let right = root.right;

  root.left = null;
  root.right = left; // connect the left subtree to the right

  // find the last node of the left subtree
  let p = root;
  while (p.right !== null) {
    p = p.right;
  }

  p.right = right;
}
