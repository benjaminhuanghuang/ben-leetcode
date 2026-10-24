/*
637. Average of Levels in Binary Tree
https://leetcode.com/problems/average-of-levels-in-binary-tree/
*/

import { TreeNode } from "../Common/TreeNode";

function averageOfLevels(root: TreeNode | null): number[] {
  const res: number[] = [];
  if (!root) {
    return res;
  }
  const queue: TreeNode[] = [root];
  while (queue.length > 0) {
    const size = queue.length; // node count of the current level
    let sum = 0;
    for (let i = 0; i < size; i++) {
      const node = queue.shift()!;
      sum += node.val;
      if (node.left) {
        queue.push(node.left);
      }
      if (node.right) {
        queue.push(node.right);
      }
    }
    res.push(sum / size);
  }
  return res;
}
