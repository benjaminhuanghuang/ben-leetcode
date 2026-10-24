/*
199. Binary Tree Right Side View
https://leetcode.com/problems/binary-tree-right-side-view/
*/

import { TreeNode } from "../Common/TreeNode";

function rightSideView(root: TreeNode | null): number[] {
  const res: number[] = [];
  if (!root) {
    return res;
  }

  const queue: TreeNode[] = [root];

  while (queue.length > 0) {
    const size = queue.length; // node count of the current level
    for (let i = 0; i < size; i++) {
      const node = queue.shift()!; // remove the first element from the queue
      if (i === size - 1) {
        res.push(node.val); // add the last element(right side) of the current level
      }

      if (node.left) {
        queue.push(node.left);
      }
      if (node.right) {
        queue.push(node.right);
      }
    }
  }

  return res;
}
