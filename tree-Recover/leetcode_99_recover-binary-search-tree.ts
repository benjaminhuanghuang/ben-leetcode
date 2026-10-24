/*
99. Recover Binary Search Tree

https://leetcode.com/problems/recover-binary-search-tree/
*/
import { TreeNode } from "../Common/TreeNode";

function recoverTree(root: TreeNode | null): void {
  let first: TreeNode | null = null;
  let second: TreeNode | null = null;
  let prev: TreeNode | null = null;

  function inorder(node: TreeNode | null) {
    if (node === null) return;

    inorder(node.left);
    // prev 是当前node的前一个node， 正常情况下 prev->val <= node->val
    if (prev !== null && prev.val >= node.val) {
      if (first === null) {
        first = prev;
      }
      second = node;
    }

    prev = node;

    inorder(node.right);
  }

  inorder(root);

  if (first && second) {
    let temp = (first as TreeNode).val;
    (first as TreeNode).val = (second as TreeNode).val;
    (second as TreeNode).val = temp;
  }
}
