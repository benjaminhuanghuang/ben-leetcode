/*
510. Inorder Successor in BST II

https://leetcode.com/problems/inorder-successor-in-bst-ii/
*/

import { TreeNode } from "../Common/TreeNode";
class Node {
  val: number;
  left: Node | null;
  right: Node | null;
  parent: Node | null;

  constructor(val: number) {
    this.val = val;
    this.left = null;
    this.right = null;
    this.parent = null;
  }
}

function inorderSuccessor(node: Node): Node | null {
  if (!node) {
    return null;
  }
  // If the node has a right child, the successor is most left in the right subtree
  if (node.right) {
    // Successor is the leftmost child of node's right subtree
    let currentNode: Node = node.right;
    while (currentNode.left) {
      currentNode = currentNode.left;
    }
    return currentNode;
  }

  /*
    When the node does not have right child, we must traverse up using the parent pointers.
    This loop stops when either node does not have a parent (meaning we have reached the root and no successor exists), 
    or when node is a left child, which means its parent is the in-order successor. 
    */
  let currentNode: Node | null = node;
  // Traverse up until no parent or current node is a left child
  while (currentNode.parent && currentNode === currentNode.parent.right) {
    currentNode = currentNode.parent;
  }
  // The successor is the parent of the detached subtree
  return currentNode.parent;
}
