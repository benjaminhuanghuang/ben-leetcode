/*
701. Insert into a Binary Search Tree

https://leetcode.com/problems/insert-into-a-binary-search-tree/
*/

import { TreeNode } from "../Common/TreeNode";

/*
Time complexity: O(logn ~ n)

Space complexity: O(logn ~ n)
*/
function insertIntoBST(root: TreeNode | null, val: number): TreeNode | null {
  if (root === null) {
    return new TreeNode(val);
  }

  // If the value to insert is greater than the root's value, recursively insert into the right subtree.
  if (val > root.val) {
    root.right = insertIntoBST(root.right, val);
  } else {
    // If the value is less than or equal to the root's value, recursively insert into the left subtree.
    root.left = insertIntoBST(root.left, val);
  }

  return root;
}
