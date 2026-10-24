/*
236. Lowest Common Ancestor of a Binary Tree

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

- 235. Lowest Common Ancestor of a Binary Search Tree
*/

import { TreeNode } from "../Common/TreeNode";

/*
    root?

    p and q are located in the different subtrees of the root

    root.left?  root.right?
*/
function lowestCommonAncestor(
  root: TreeNode | null,
  p: TreeNode | null,
  q: TreeNode | null
): TreeNode | null {
  // termination condition
  if (!root || root === p || root === q) {
    return root;
  }

  const left = lowestCommonAncestor(root.left, p, q);
  const right = lowestCommonAncestor(root.right, p, q);

  if (left && right) {
    return root;
  }

  return left || right;
}
