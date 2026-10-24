/*
2331. Evaluate Boolean Binary Tree

https://leetcode.com/problems/evaluate-boolean-binary-tree/
*/

import { TreeNode } from "../Common/TreeNode";

function evaluateTree(root: TreeNode | null): boolean {
  if (root === null) return false;

  if (root.left === null && root.right === null) {
    return root.val === 1;
  }

  const left = evaluateTree(root.left);
  const right = evaluateTree(root.right);
  return root.val === 2 ? left || right : left && right;
}
