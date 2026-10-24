/*
530. Minimum Absolute Difference in BST

*/

import { TreeNode } from "../Common/TreeNode";

/*
https://www.youtube.com/watch?v=0JHrHh_mIIw
HuaHua
*/

/*
https://algo.monster/liteproblems/530

*/
function getMinimumDifference(root: TreeNode | null): number {
  let prev = Number.MIN_SAFE_INTEGER;
  let minDifference = Number.MAX_SAFE_INTEGER;

  // Recursive function to perform in-order traversal on a binary search tree.
  const dfsInorderTraversal = (node: TreeNode | null) => {
    if (!node) return;

    dfsInorderTraversal(node.left);

    // Process the current node by updating the minDifference with the absolute difference
    // between the current node's value and the previous value if previousValue is valid.
    minDifference = Math.min(minDifference, node.val - prev);
    prev = node.val;

    dfsInorderTraversal(node.right);
  };

  dfsInorderTraversal(root);

  return minDifference;
}
