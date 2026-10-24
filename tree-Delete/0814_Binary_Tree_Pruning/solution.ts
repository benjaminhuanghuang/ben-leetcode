/*
814. Binary Tree Pruning

https://leetcode.com/problems/binary-tree-pruning/

 把不含有1的节点的子树全部删除。
*/

import { TreeNode } from "../Common/TreeNode";

function pruneTree(root: TreeNode | null): TreeNode | null {
  if (!root) return null;

  root.left = pruneTree(root.left);
  root.right = pruneTree(root.right);
  // If the current node is 0 and it has no children, return null
  if (root.val == 1 || root.left || root.right) return root;
  return null;
}
