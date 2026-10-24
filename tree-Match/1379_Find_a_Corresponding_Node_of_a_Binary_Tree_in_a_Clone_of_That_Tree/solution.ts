/*
1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree

https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
*/

import { TreeNode } from "../Common/TreeNode";

function getTargetCopy(
  original: TreeNode | null,
  cloned: TreeNode | null,
  target: TreeNode | null
): TreeNode | null {
  const dfs = (
    nodeOriginal: TreeNode | null,
    nodeCloned: TreeNode | null
  ): TreeNode | null => {
    if (!nodeOriginal) {
      return null;
    }
    if (nodeOriginal === target) {
      // Found the target node
      return nodeCloned;
    }
    return (
      dfs(nodeOriginal.left, nodeCloned!.left) ||
      dfs(nodeOriginal.right, nodeCloned!.right)
    );
  };

  // Start DFS from the Root nodes of both trees
  return dfs(original, cloned);
}
