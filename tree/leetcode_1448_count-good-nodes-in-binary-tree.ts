/*
1448. Count Good Nodes in Binary Tree

https://leetcode.com/problems/count-good-nodes-in-binary-tree/
*/

import { TreeNode } from "../Common/TreeNode";

/*
pre-order traversal, pass the maximum value from the root to the current node
*/
function goodNodes(root: TreeNode | null): number {
  let goodNodesCount = 0;
  // pre-order traversal
  function dfs(node: TreeNode | null, maxSoFar: number): void {
    if (!node) {
      return;
    }
    if (maxSoFar <= node.val) {
      goodNodesCount++;
      maxSoFar = node.val; // Update maxSoFar if the current node has a higher value
    }
    // Traverse left and right subtrees
    dfs(node.left, maxSoFar);
    dfs(node.right, maxSoFar);
  }

  dfs(root, Number.MIN_SAFE_INTEGER); // Start DFS with the lowest possible value
  return goodNodesCount; // Return the count of good nodes
}
