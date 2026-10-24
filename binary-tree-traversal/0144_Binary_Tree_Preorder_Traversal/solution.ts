/*
144. Binary Tree Preorder Traversal

https://leetcode.com/problems/binary-tree-preorder-traversal/
*/

import { TreeNode } from "../Common/TreeNode";

function preorderTraversal(root: TreeNode | null): number[] {
  const result: number[] = [];

  function traverse(node: TreeNode | null) {
    if (node === null) return;
    result.push(node.val); // Visit the node first
    traverse(node.left);
    traverse(node.right);
  }

  traverse(root);
  return result;
}

function preOrderTraversal(root: TreeNode | null): number[] {
  const result: number[] = [];
  if (root === null) return result;

  const stack: TreeNode[] = [root];

  while (stack.length > 0) {
    const node = stack.pop()!;
    result.push(node.val);

    if (node.right !== null) {
      stack.push(node.right);
    }
    // in the stack, the left node will be popped out before the right node
    if (node.left !== null) {
      stack.push(node.left);
    }
  }

  return result;
}
