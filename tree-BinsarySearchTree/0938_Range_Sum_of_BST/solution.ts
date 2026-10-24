/*
938. Range Sum of BST

https://leetcode.com/problems/range-sum-of-bst/
*/

import { TreeNode } from "../Common/TreeNode";

function rangeSumBST(root: TreeNode | null, low: number, high: number): number {
  if (!root) {
    return 0;
  }

  // Check if the current node's value is within the range [low, high].
  if (root.val >= low && root.val <= high) {
    // The node's value falls within the range, so add it to the sum,
    // and continue to check both the left and right subtrees.
    return (
      root.val +
      rangeSumBST(root.left, low, root.val) +
      rangeSumBST(root.right, root.val, high)
    );
  } else if (root.val < low) {
    // The current node's value is less than the low end of the range,
    // so there is no need to check the left subtree (all values will be too small).
    // Instead, traverse the right subtree only.
    return rangeSumBST(root.right, low, high);
  } else {
    // The current node's value is greater than the high end of the range,
    // so there is no need to check the right subtree (all values will be too large).
    // Instead, traverse the left subtree only.
    return rangeSumBST(root.left, low, high);
  }
}
