/*
450. Delete Node in a BST

https://leetcode.com/problems/delete-node-in-a-bst/
*/

import { TreeNode } from "../Common/TreeNode";

function deleteNode(root: TreeNode | null, key: number): TreeNode | null {
  if (root === null) {
    return root;
  }

  if (key > root.val) {
    root.right = deleteNode(root.right, key);
  } else if (key < root.val) {
    root.left = deleteNode(root.left, key);
  } else {
    // root is the node to be deleted, and root has two children
    // use the new root will be the minimum node in the right subtree
    if (root.left !== null && root.right !== null) {
      let minNode = root.right;
      while (minNode.left !== null) {
        minNode = minNode.left;
      }
      root.val = minNode.val;
      root.right = deleteNode(root.right, minNode.val);
    } else {
      // root has at most one child, the new root is the child node
      let newRoot = root.left === null ? root.right : root.left;
      root.left = root.right = null;
      return newRoot;
    }
  }

  return root;
}
