/*
671. Second Minimum Node In a Binary Tree

https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

More formally, the property root.val = min(root.left.val, root.right.val) always holds.
*/

import { TreeNode } from "../Common/TreeNode";

function findSecondMinimumValue(root: TreeNode | null): number {
  if (root === null) return -1;

  return DFS(root, root.val);
}

//s1 is the smallest value in the tree
function DFS(root: TreeNode | null, s1: number): number {
  if (root === null) return -1;

  // If root's value is already greater than s1,
  // then all its children's values should be >= s1.
  // Thus root's value is the second smallest one.
  if (root.val > s1) return root.val;

  const sl = DFS(root.left, s1);
  const sr = DFS(root.right, s1);

  if (sl === -1) return sr;
  if (sr === -1) return sl;

  // Return the smaller one among the two subtrees
  return Math.min(sl, sr);
}
