/*
314. Binary Tree Vertical Order Traversal

https://leetcode.com/problems/binary-tree-vertical-order-traversal/

[Meta]

*/

import { TreeNode } from "../Common/TreeNode";

/*
    https://www.youtube.com/watch?v=KrT_qcGj4nA

    https://algo.monster/liteproblems/314

    以root为对称轴，左右各多少node，最终结果就有几个list
 */

// Returns a list of vertical order traversal of a binary tree.
function verticalOrder(root: TreeNode | null): number[][] {
  // Stores the result of the vertical order traversal.
  let verticalTraversal: number[][] = [];

  if (!root) return verticalTraversal; // If the tree is empty, return an empty list.

  // Map to store the column number and the list of nodes at that column.
  const nodesInCol = new Map<number, number[]>();
  const queue: Array<{ node: TreeNode; column: number }> = [];

  queue.push({ node: root, column: 0 }); // Initialize queue with the root node at column 0.

  // Perform a breadth-first traversal of the tree.
  while (queue.length > 0) {
    const levelSize = queue.length; // Number of elements at the current level.
    for (let i = 0; i < levelSize; ++i) {
      const { node: currentNode, column } = queue.shift()!; // Get and remove the front item from the queue.
      // get the column number of the current node from the queue.
      // Append current node's value to its column list.
      if (!nodesInCol.has(column)) {
        nodesInCol.set(column, []);
      }
      nodesInCol.get(column)!.push(currentNode.val);

      // the colum of the root is 0, column of the left child is column - 1, column of the right child is column + 1
      // If left or right child exists, add them to queue with updated column value.
      if (currentNode.left) {
        queue.push({ node: currentNode.left, column: column - 1 });
      }
      if (currentNode.right) {
        queue.push({ node: currentNode.right, column: column + 1 });
      }
    }
  }

  // Transfer the values from the column table map into the final sorted array.
  // The map's keys are sorted, so traversal will be vertical and from left to right.
  const sortedColumns = Array.from(nodesInCol.keys()).sort((a, b) => a - b);
  for (const column of sortedColumns) {
    verticalTraversal.push(nodesInCol.get(column)!);
  }

  return verticalTraversal; // Return the organized list of values.
}
