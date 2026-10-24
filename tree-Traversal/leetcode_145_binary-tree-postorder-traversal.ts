/*
145. Binary Tree Postorder Traversal

https://leetcode.com/problems/binary-tree-postorder-traversal/
*/

import { TreeNode } from "../Common/TreeNode";

function postorderTraversal(root: TreeNode | null): number[] {
  const result: number[] = [];
  if (root === null) return result;

  const stack: TreeNode[] = [];
  const output: TreeNode[] = [];
  stack.push(root);

  while (stack.length > 0) {
    const node = stack.pop()!;
    output.push(node);

    if (node.left !== null) {
      stack.push(node.left);
    }
    if (node.right !== null) {
      stack.push(node.right);
    }
  }
  // output is the reverse of post-order traversal
  while (output.length > 0) {
    const node = output.pop()!;
    result.push(node.val);
  }

  return result;
}

function postOrderTraversal_2(root: TreeNode | null): number[] {
  const result: number[] = [];
  function traverse(node: TreeNode | null) {
    if (node === null) return;
    traverse(node.left);
    traverse(node.right);
    result.push(node.val);
  }
  traverse(root);
  return result;
}
