/*
222. Count Complete Tree Nodes
https://leetcode.com/problems/count-complete-tree-nodes/

Design an algorithm that runs in less than O(n) time complexity.
*/

import { TreeNode } from "../Common/TreeNode";

/*
    Time complexity - 0(n)
    Space complexity - O(h), where h is the height of the binary tree.
*/
function countNodes(root: TreeNode | null): number {
  if (root == null) return 0;
  let count = 1;
  if (root.left != null) count += countNodes(root.left);
  if (root.right != null) count += countNodes(root.right);

  return count;
}
