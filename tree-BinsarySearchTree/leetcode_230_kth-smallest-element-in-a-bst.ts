/* 
230. Kth Smallest Element in a BST
https://leetcode.com/problems/kth-smallest-element-in-a-bst/
*/

import { TreeNode } from "../Common/TreeNode";

/*
    Using inorder traversal to get the kth smallest element
*/
function kthSmallest(root: TreeNode | null, k: number): number {
  let count = 0;
  let res = 0;

  function inorder(node: TreeNode | null) {
    if (node === null) {
      return;
    }

    inorder(node.left);
    count++;
    if (count === k) {
      res = node.val;
      return;
    }
    inorder(node.right);
  }

  inorder(root);
  return res;
}
