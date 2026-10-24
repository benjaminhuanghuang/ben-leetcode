/*
110. Balanced Binary Tree

https://leetcode.com/problems/balanced-binary-tree/
*/

import { TreeNode } from "../Common/TreeNode";

/*
O(N)
get 2 information in the helper function : height and isBalance
*/
function isBalanced(root: TreeNode | null): boolean {
  let balanced = true;

  function height(root: TreeNode | null): number {
    if (!root) return 0;
    const leftHeight = height(root.left);
    if (!balanced) return -1;
    const rightHeight = height(root.right);
    if (!balanced) return -1;
    if (Math.abs(leftHeight - rightHeight) > 1) {
      balanced = false;
      return -1;
    }
    return Math.max(leftHeight, rightHeight) + 1;
  }
  height(root);
  return balanced;
}

/*
    O(N*logN)
*/
function isBalanced2(root: TreeNode | null): boolean {
  if (!root) return true;
  const leftHeight = height(root.left);
  const rightHeight = height(root.right);
  return (
    Math.abs(leftHeight - rightHeight) <= 1 &&
    isBalanced(root.left) &&
    isBalanced(root.right)
  );
}

function height(root: TreeNode | null): number {
  if (!root) return 0;
  return Math.max(height(root.left), height(root.right)) + 1;
}
