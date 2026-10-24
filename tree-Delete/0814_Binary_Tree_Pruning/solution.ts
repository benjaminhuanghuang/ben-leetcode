import { TreeNode } from "../../common/TreeNode";

function pruneTree(root: TreeNode | null): TreeNode | null {
  if (!root) return null;

  root.left = pruneTree(root.left);
  root.right = pruneTree(root.right);
  // If the current node is 0 and it has no children, return null
  if (root.val == 1 || root.left || root.right) return root;
  return null;
}
