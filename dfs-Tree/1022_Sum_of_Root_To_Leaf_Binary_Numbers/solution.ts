/*
1022. Sum of Root To Leaf Binary Numbers

https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
*/

import { TreeNode } from "../Common/TreeNode";

function sumRootToLeaf(root: TreeNode | null): number {
  function dfs(node: TreeNode | null, currentNumber: number): number {
    if (node === null) {
      return 0;
    }

    // Update the binary number by shifting left and adding the current node's value.
    currentNumber = (currentNumber << 1) | node.val;

    if (node.left === null && node.right === null) {
      return currentNumber;
    }
    return dfs(node.left, currentNumber) + dfs(node.right, currentNumber);
  }

  // Initialize the sum from the root node with 0 as the initial binary number.
  return dfs(root, 0);
}
