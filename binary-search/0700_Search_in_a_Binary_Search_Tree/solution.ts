import { TreeNode } from "../../common/TreeNode";

function searchBST(root: TreeNode | null, val: number): TreeNode | null {
  if (root == null) return null;

  if (val == root.val) return root;
  else if (val > root.val) return searchBST(root.right, val);

  return searchBST(root.left, val);
}
