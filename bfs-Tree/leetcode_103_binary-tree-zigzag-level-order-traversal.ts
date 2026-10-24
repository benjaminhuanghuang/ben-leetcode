/*
103. Binary Tree Zigzag Level Order Traversal
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
*/

import { TreeNode } from "../Common/TreeNode";

function zigzagLevelOrder(root: TreeNode | null): number[][] {
  if (root === null) {
    return [];
  }
  const result: number[][] = [];
  const queue: TreeNode[] = [root];
  let isReverse = false; // To keep track of the direction of traversal

  while (queue.length > 0) {
    const levelSize = queue.length;
    const level: number[] = [];

    for (let i = 0; i < levelSize; i++) {
      const node = queue.shift()!;
      level.push(node.val);

      if (node.left !== null) {
        queue.push(node.left);
      }

      if (node.right !== null) {
        queue.push(node.right);
      }
    }

    result.push(isReverse ? level.reverse() : level);
    isReverse = !isReverse;
  }

  return result;
}
