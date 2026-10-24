/*
173. Binary Search Tree Iterator
https://leetcode.com/problems/binary-search-tree-iterator/

94. Binary Tree Inorder Traversal
*/

import { TreeNode } from "../Common/TreeNode";
/*
Use a stack to simulate the inorder traversal of the BST.
Time complexity: amortized O(1) for next() call.
Space complexity: O(n) for the stack.
*/
class BSTIterator {
  private stack: TreeNode[];
  constructor(root: TreeNode | null) {
    this.stack = [];
    this.pushLeftNodes(root);
  }

  next(): number {
    if (this.stack.length === 0) {
      return -1;
    }
    const current = this.stack.pop() as TreeNode;
    this.pushLeftNodes(current.right);
    return current.val;
  }

  hasNext(): boolean {
    return this.stack.length > 0;
  }

  // Push all left nodes onto the stack
  private pushLeftNodes(node: TreeNode | null): void {
    while (node !== null) {
      this.stack.push(node);
      node = node.left;
    }
  }
}
