/*
563. Binary Tree Tilt

https://leetcode.com/problems/binary-tree-tilt/
*/

import { TreeNode } from "../Common/TreeNode";

function findTilt(root: TreeNode | null): number {
  return helper(root)[0];
}

// calculate the tilt of the root and the sum of the root in one function
function helper(root: TreeNode | null): number[] {
  if (root == null) return [0, 0];

  const left = helper(root.left);
  const right = helper(root.right);
  // result[0] = sum tilt of l + sum tilt of r + tilt of root
  // result[1] = sum of node = node.val + sum of left + sum of right
  return [
    left[0] + right[0] + Math.abs(left[1] - right[1]),
    root.val + left[1] + right[1],
  ];
}
