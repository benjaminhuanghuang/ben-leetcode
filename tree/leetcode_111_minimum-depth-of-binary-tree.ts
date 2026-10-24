/*
111. Minimum Depth of Binary Tree

https://leetcode.com/problems/minimum-depth-of-binary-tree/
*/

import { TreeNode } from "../Common/TreeNode";

/*
注意：如果只有左子树或者右子树，最小深度是左子树或者右子树的最小深度+1， 而不是1

*/
function minDepth(root: TreeNode | null): number {
  if (!root) return 0;

  if (!root.left && !root.right) return 1;

  let min = Number.MAX_SAFE_INTEGER;

  if (root.left) {
    min = Math.min(min, minDepth(root.left));
  }

  if (root.right) {
    min = Math.min(min, minDepth(root.right));
  }

  return min + 1;
}
