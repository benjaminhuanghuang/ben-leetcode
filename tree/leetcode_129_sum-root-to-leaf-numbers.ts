/*
129. Sum Root to Leaf Numbers

https://leetcode.com/problems/sum-root-to-leaf-numbers/
*/

import { TreeNode } from "../Common/TreeNode";

/*
 The root is the higest digit and the leaf is the lowest digit.
*/
function sumNumbers(root: TreeNode | null): number {
  return dfs(root, 0);
}

function dfs(root: TreeNode | null, sum: number): number {
  if (root === null) {
    return 0;
  }
  sum = sum * 10 + root.val;

  if (root.left === null && root.right === null) {
    return sum;
  }

  return dfs(root.left, sum) + dfs(root.right, sum);
}
