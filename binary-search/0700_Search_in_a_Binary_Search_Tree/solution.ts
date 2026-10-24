/*
700. Search in a Binary Search Tree

https://leetcode.com/problems/search-in-a-binary-search-tree/
*/

import { TreeNode } from "../Common/TreeNode";

function searchBST(root: TreeNode | null, val: number): TreeNode | null {
  if (root == null) return null;

  if (val == root.val) return root;
  else if (val > root.val) return searchBST(root.right, val);

  return searchBST(root.left, val);
}
