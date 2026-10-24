/*
98. Validate Binary Search Tree
https://leetcode.com/problems/validate-binary-search-tree/
*/

import { TreeNode } from "../Common/TreeNode";

function isValidBST(root: TreeNode | null): boolean {
  function validate(
    node: TreeNode | null,
    lower: number,
    upper: number
  ): boolean {
    if (node === null) {
      return true;
    }

    if (node.val <= lower) {
      return false;
    }

    if (node.val >= upper) {
      return false;
    }

    return (
      validate(node.left, lower, node.val) &&
      validate(node.right, node.val, upper)
    );
  }
  return validate(root, Number.MIN_SAFE_INTEGER, Number.MAX_SAFE_INTEGER);
}
