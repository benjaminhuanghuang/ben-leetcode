/*
919. Complete Binary Tree Inserter

https://leetcode.com/problems/complete-binary-tree-inserter/

CBTInserter.insert(int v) 将 TreeNode 插入到存在值为 node.val = v 的树中以使其保持完全二叉树的状态，
并返回插入的 TreeNode 的父结点的值；
*/

import { TreeNode } from "../Common/TreeNode";

class CBTInserter {
  private root: TreeNode;
  private queue: Array<TreeNode>;

  constructor(root: TreeNode) {
    this.root = root;
    this.queue = [root];

    // Initialize the deque to ensure it starts from the first incomplete level
    let i = 0; // The index of the first node in the current level
    while (i < this.queue.length) {
      const node = this.queue[i];
      if (node.left) this.queue.push(node.left);
      if (node.right) this.queue.push(node.right);
      i++;
    }
  }

  insert(v: number): number {
    const newNode = new TreeNode(v);
    for (let node of this.queue) {
      if (!node.left) {
        node.left = newNode;
        this.queue.push(newNode);
        return node.val;
      } else if (!node.right) {
        node.right = newNode;
        this.queue.push(newNode);
        this.queue.shift(); // Move to the next node in the queue
        return node.val;
      }
    }
    return -1; // This should not be reached if the tree was initialized correctly
  }

  get_root(): TreeNode {
    return this.root;
  }
}
