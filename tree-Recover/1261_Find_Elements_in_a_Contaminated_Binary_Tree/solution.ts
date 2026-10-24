/*
1261. Find Elements in a Contaminated Binary Tree

https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
*/

import { TreeNode } from "../Common/TreeNode";

/*
https://algo.monster/liteproblems/1261
At the start, all node have valu -1
*/
class FindElements {
  recoveredValues = new Set<number>();

  constructor(root: TreeNode | null) {
    // Start by setting the root value to 0, as per the problem statement.
    root!.val = 0;
    // Start recovering the tree from the root.
    this.recoverTree(root!);
  }

  find(target: number): boolean {
    return this.recoveredValues.has(target);
  }

  // Helper function to recover the tree.
  recoverTree(node: TreeNode): void {
    // Store the recovered value in the set.
    this.recoveredValues.add(node.val);

    // If the left child exists, set its value and recover its subtree.
    if (node.left) {
      node.left.val = node.val * 2 + 1;
      this.recoverTree(node.left);
    }

    // If the right child exists, set its value and recover its subtree.
    if (node.right) {
      node.right.val = node.val * 2 + 2;
      this.recoverTree(node.right);
    }
  }
}
