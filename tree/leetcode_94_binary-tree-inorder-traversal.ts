/* 
94. Binary Tree Inorder Traversal
https://leetcode.com/problems/binary-tree-inorder-traversal/
*/

import { TreeNode } from "../Common/TreeNode";

/*
iterative approach 

Time complexity: O(n) where n is the number of nodes in the tree
*/
function inorderTraversal(root: TreeNode | null): number[] {
  const result: number[] = [];
  const stack: TreeNode[] = [];
  let current: TreeNode | null = root;

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

/*

Space complexity: O(h) space complexity where h is the height of the tree due to the call stack
*/
function inorderTraversal_recursion(root: TreeNode | null): number[] {
  // Base case: if the current root is null, return an empty array.
  if (root === null) {
    return [];
  }

  // Recursive case:
  // 1. Traverse the left subtree and collect the values.
  // 2. Include the value of the current node.
  // 3. Traverse the right subtree and collect the values.
  // Then concatenate them in inorder sequence.
  return [
    ...inorderTraversal(root.left), // Left subtree values
    root.val, // Current node value
    ...inorderTraversal(root.right), // Right subtree values
  ];
}
