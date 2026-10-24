/*
1026. Maximum Difference Between Node and Ancestor

https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
*/

import { TreeNode } from "../Common/TreeNode";

function maxAncestorDiff(root: TreeNode | null): number {
  if (root === null) {
    return 0;
  }
  let maxDifference: number = 0;
  function dfs(node: TreeNode | null, minVal: number, maxVal: number): void {
    if (!node) {
      return;
    }

    // Calculate the potential new max differences with the current node
    const potentialMaxDiff = Math.max(
      Math.abs(node.val - minVal),
      Math.abs(node.val - maxVal)
    );

    // Update the global maxDifference if the new potential difference is greater
    maxDifference = Math.max(maxDifference, potentialMaxDiff);

    // Update the min and max values seen so far after considering the current node's value
    const newMinVal = Math.min(minVal, node.val);
    const newMaxVal = Math.max(maxVal, node.val);

    // Continue the DFS traversal for left and right children
    dfs(node.left, newMinVal, newMaxVal);
    dfs(node.right, newMinVal, newMaxVal);
  }
  dfs(root, root.val, root.val);

  return maxDifference;
}
