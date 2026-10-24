/*
1325. Delete Leaves With a Given Value

https://leetcode.com/problems/delete-leaves-with-a-given-value/
*/

import { TreeNode } from "../Common/TreeNode";

function removeLeafNodes(
  root: TreeNode | null,
  target: number
): TreeNode | null {
  if (!root) {
    return null;
  }

  root.left = removeLeafNodes(root.left, target);
  root.right = removeLeafNodes(root.right, target);

  // Check if the current node has become a leaf node with the value equal to target.
  // If so, remove this node by returning null; otherwise, return the current node.
  if (root.left === null && root.right === null && root.val === target) {
    return null;
  } else {
    return root;
  }
}
