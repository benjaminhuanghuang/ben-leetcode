/*
250. Count Univalue Subtrees

https://leetcode.com/problems/count-univalue-subtrees/
*/

import { TreeNode } from "../Common/TreeNode";

function countUnivalSubtrees(root: TreeNode | null): number {
  let count: number = 0;

  // Helper function to perform depth-first search.
  // Returns true if the subtree rooted at the given node is universal.
  const isUnivalSubtree = (node: TreeNode | null): boolean => {
    if (node == null) {
      // A null node is considered a universal subtree.
      return true;
    }

    // Recursively check the left and right subtrees.
    const isLeftUnival: boolean = isUnivalSubtree(node.left);
    const isRightUnival: boolean = isUnivalSubtree(node.right);

    // If either subtree is not universal, then this cannot be a universal subtree.
    if (!isLeftUnival || !isRightUnival) {
      return false;
    }

    // If left child exists and its value is not equal to current node's value, this is not a universal subtree.
    if (node.left != null && node.left.val != node.val) {
      return false;
    }

    // If right child exists and its value is not equal to current node's value, this is not a universal subtree.
    if (node.right != null && node.right.val != node.val) {
      return false;
    }

    // Current subtree is universal; increment count and return true.
    count++;
    return true;
  };

  // Kick-off the depth-first search from the root.
  isUnivalSubtree(root);

  // Return the final count of universal subtrees.
  return count;
}
