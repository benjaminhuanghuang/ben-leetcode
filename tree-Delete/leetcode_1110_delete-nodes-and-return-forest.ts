/*
1110. Delete Nodes And Return Forest

https://leetcode.com/problems/delete-nodes-and-return-forest/
*/

import { TreeNode } from "../Common/TreeNode";

/*
https://algo.monster/liteproblems/1110
*/

function delNodes(
  root: TreeNode | null,
  to_delete: number[]
): Array<TreeNode | null> {
  // Array to track whether a value should be deleted or not.
  // Initialized as false, as true values will be assigned based on the toDelete array.
  const toBeDeleted: boolean[] = Array(1001).fill(false);
  // Mark the values that need to be deleted
  for (const value of to_delete) {
    toBeDeleted[value] = true;
  }

  // Resulting array of tree roots that form the forest after deletions.
  const forest: Array<TreeNode | null> = [];

  /**
   * The Depth-first Search (DFS) function to traverse the tree and make deletions.
   * @param {TreeNode | null} node - The current node being processed.
   * @return {TreeNode | null} - The new tree with deletions, or null if node is deleted.
   */
  const dfs = (node: TreeNode | null): TreeNode | null => {
    if (!node) {
      return null;
    }

    // Recursively apply the DFS to the left and right children.
    node.left = dfs(node.left);
    node.right = dfs(node.right);
    // If the current node should not be deleted, return it as is.
    if (!toBeDeleted[node.val]) {
      return node;
    }

    // If the node should be deleted and has a left child, add it to the forest array.
    if (node.left) {
      forest.push(node.left);
    }
    // If the node should be deleted and has a right child, add it to the forest array.
    if (node.right) {
      forest.push(node.right);
    }
    // Returning null indicates that the current node has been deleted.
    return null;
  };

  // Kick-off DFS from the root. If the root is not deleted, add it to the forest array.
  if (dfs(root)) {
    forest.push(root);
  }

  return forest;
}
