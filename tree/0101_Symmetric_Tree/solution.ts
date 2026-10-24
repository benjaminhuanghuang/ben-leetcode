/*
101. Symmetric Tree
https://leetcode.com/problems/symmetric-tree/
*/
import { TreeNode } from "../Common/TreeNode";

function isSymmetric(root: TreeNode | null): boolean {
  if (root === null) {
    return true;
  }

  function isMirror(left: TreeNode | null, right: TreeNode | null): boolean {
    if (left === null && right === null) {
      return true;
    }
    if (left === null || right === null) {
      return false;
    }
    return (
      left.val === right.val &&
      isMirror(left.left, right.right) &&
      isMirror(left.right, right.left)
    );
  }

  return root.left?.val === root.right?.val && isMirror(root.left, root.right);
}
