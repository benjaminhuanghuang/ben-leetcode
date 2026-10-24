/*
94. Binary Tree Inorder Traversal

https://leetcode.com/problems/binary-tree-inorder-traversal/
*/

import { TreeNode } from "../Common/TreeNode";

/*

*/
function inorderTraversal(root: TreeNode | null): number[] {
  const result: number[] = [];
  const stack: TreeNode[] = [];
  let current: TreeNode | null = root;

  // still have nodes to visit or there are nodes waiting in the stack
  while (current !== null || stack.length > 0) {
    // Push all left nodes onto the stack
    while (current !== null) {
      stack.push(current);
      current = current.left;
    }

    // Visit current node (leftmost node)
    current = stack.pop()!;
    result.push(current.val);

    // Move to the right subtree
    current = current.right;
  }

  return result;
}

function inOrderTraversal_2(root: TreeNode | null): number[] {
  const result: number[] = [];
  function traverse(node: TreeNode | null) {
    if (node === null) return;
    traverse(node.left);
    result.push(node.val); // Visit the node in the middle
    traverse(node.right);
  }
  traverse(root);
  return result;
}
