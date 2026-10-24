/*
2641. Cousins in Binary Tree II

https://leetcode.com/problems/cousins-in-binary-tree-ii/

Two nodes of a binary tree are cousins if they have the same depth with different parents.

- 993. Cousins in Binary Tree
*/

import { TreeNode } from "../Common/TreeNode";

function replaceValueInTree(root: TreeNode | null): TreeNode | null {
  // An array to store the sum of values at each depth.
  const sumAtDepth: number[] = [];

  // First depth-first search to collect sums at each depth.
  collectSumByDepth(root, 0, sumAtDepth);

  // Set the root's value to 0 as per instructions.
  if (root) {
    root.val = 0;
  }

  // Second depth-first search to replace the node values by the collected sums at each depth.
  replaceNodeValueByDepth(root, 1, sumAtDepth);

  return root;
}

// This function performs a depth-first traversal to collect the sum of values at each depth.
function collectSumByDepth(
  root: TreeNode | null,
  depth: number,
  sumAtDepth: number[]
): void {
  if (!root) return;

  // Ensure the array is large enough to hold the sum for the current depth.
  if (sumAtDepth.length <= depth) {
    sumAtDepth.push(0);
  }

  // Add the current node's value to the sum corresponding to its depth.
  sumAtDepth[depth] += root.val;

  // Traverse the left and right children.
  collectSumByDepth(root.left, depth + 1, sumAtDepth);
  collectSumByDepth(root.right, depth + 1, sumAtDepth);
}

function replaceNodeValueByDepth(
  root: TreeNode | null,
  depth: number,
  sumAtDepth: number[]
): void {
  if (!root) return;

  // The sum of the values of the children nodes.
  const childSum = (root.left?.val ?? 0) + (root.right?.val ?? 0);

  // Replace the value of the left child if it exists.
  if (root.left) {
    root.left.val = sumAtDepth[depth] - childSum;
  }

  // Replace the value of the right child if it exists.
  if (root.right) {
    root.right.val = sumAtDepth[depth] - childSum;
  }

  // Continue the traversal for left and right children.
  replaceNodeValueByDepth(root.left, depth + 1, sumAtDepth);
  replaceNodeValueByDepth(root.right, depth + 1, sumAtDepth);
}
