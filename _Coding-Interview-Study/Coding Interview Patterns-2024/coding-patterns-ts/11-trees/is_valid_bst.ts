import { TreeNode } from "./tree";

function isValidBST(root: TreeNode | null): boolean {
  return isWithinBounds(root, -Infinity, Infinity);
}

// Helper function with bounds
function isWithinBounds(
  node: TreeNode | null,
  lowerBound: number,
  upperBound: number
): boolean {
  if (!node) return true;

  if (!(lowerBound < node.val && node.val < upperBound)) {
    return false;
  }

  if (!isWithinBounds(node.left, lowerBound, node.val)) {
    return false;
  }

  return isWithinBounds(node.right, node.val, upperBound);
}
