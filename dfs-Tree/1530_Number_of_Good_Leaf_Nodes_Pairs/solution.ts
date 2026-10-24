/*
1530. Number of Good Leaf Nodes Pairs

https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
*/

import { TreeNode } from "../Common/TreeNode";

/*
https://youtu.be/g8AVmVhNTkM (HuaHua)
*/
function countPairs(root: TreeNode | null, distance: number): number {
  if (!root) return 0;

  // Count pairs in the left and right subtrees recursively
  let pairCount =
    countPairs(root.left, distance) + countPairs(root.right, distance);
  let leftDistances = new Array(distance).fill(0); // To hold counts of distances in the left subtree
  let rightDistances = new Array(distance).fill(0); // To hold counts of distances in the right subtree

  // Fill the distance arrays with count of leaves at each distance from the root
  calculateDistances(root.left, leftDistances, 1);
  calculateDistances(root.right, rightDistances, 1);

  // Combine counts from left and right to calculate distinct leaf pairs
  for (let i = 0; i < distance; i++) {
    for (let j = 0; j < distance; j++) {
      if (i + j + 2 <= distance) {
        pairCount += leftDistances[i] * rightDistances[j];
      }
    }
  }

  return pairCount;
}

// Helper DFS function to count the number of leaves at each distance 'i' from the given node.
function calculateDistances(
  node: TreeNode | null,
  counts: number[],
  currentDistance: number
): void {
  if (!node || currentDistance >= counts.length) {
    return;
  }
  // If it's a leaf node, increment the count for its distance
  if (!node.left && !node.right) {
    counts[currentDistance]++;
    return;
  }
  // Continue the DFS traversal for left and right children
  calculateDistances(node.left, counts, currentDistance + 1);
  calculateDistances(node.right, counts, currentDistance + 1);
}

/*
https://youtu.be/g8AVmVhNTkM (HuaHua)
*/
