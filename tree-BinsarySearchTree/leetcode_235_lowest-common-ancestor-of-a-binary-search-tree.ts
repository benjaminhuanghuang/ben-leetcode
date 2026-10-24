/*
235. Lowest Common Ancestor of a Binary Search Tree

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/


- 236. Lowest Common Ancestor of a Binary Tree 
*/

import { TreeNode } from "../Common/TreeNode";

function lowestCommonAncestor(
  root: TreeNode | null,
  p: TreeNode | null,
  q: TreeNode | null
): TreeNode | null {
  if (root === null) return null;

  if (root.val > p!.val && root.val > q!.val) {
    // left part
    return lowestCommonAncestor(root.left, p, q);
  } else if (root.val < p!.val && root.val < q!.val) {
    // right part
    return lowestCommonAncestor(root.right, p, q);
  }
  // root.val >= p.val && root.val <= q.val
  return root;
}
