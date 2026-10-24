/*
653. Two Sum IV - Input is a BST

https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
*/

import { TreeNode } from "../Common/TreeNode";

/*

*/
function findTarget(root: TreeNode | null, k: number): boolean {
  const set = new Set<number>(); // put every node's value into the set
  return find(root, k, set);
}

function find(root: TreeNode | null, k: number, set: Set<number>): boolean {
  if (root === null) return false;
  if (set.has(k - root.val)) return true; // find the target

  set.add(root.val);

  return find(root.left, k, set) || find(root.right, k, set);
}
