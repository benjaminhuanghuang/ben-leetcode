/*
226. Invert Binary Tree
https://leetcode.com/problems/invert-binary-tree/
*/

import { TreeNode } from "../Common/TreeNode";

function invertTree(root: TreeNode | null): TreeNode | null {
  if (root === null) {
    return null;
  }

  const left = invertTree(root.left);
  const right = invertTree(root.right);

  root.right = left;
  root.left = right;
  return root;
}
