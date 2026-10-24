/*
104. Maximum Depth of Binary Tree
https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/

import { TreeNode } from "../Common/TreeNode";

function maxDepth(root: TreeNode | null): number {
  if (root === null) {
    return 0;
  }

  const left = maxDepth(root.left);
  const right = maxDepth(root.right);
  return Math.max(left, right) + 1;
}
