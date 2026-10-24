/*
572. Subtree of Another Tree

https://leetcode.com/problems/subtree-of-another-tree/
*/
import { TreeNode } from "../Common/TreeNode";

/*
Time Complexity: O(m*n), 
m is the number of nodes in the root tree and n is the number of nodes in the subRoot tree. 
For each node of the root, we perform a depth-first search (DFS) comparison with the subRoot, which is O(n) for each call. Since the DFS might be called for each node in the root, this results in O(m*n) in the worst case.
*/
function isSubtree(root: TreeNode | null, subRoot: TreeNode | null): boolean {
  if (subRoot === null) return true;
  if (root === null) return false;
  if (isSameTree(root, subRoot)) return true;
  return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
}

function isSameTree(p: TreeNode | null, q: TreeNode | null): boolean {
  if (p === null && q === null) return true;
  if (p === null || q === null) return false;
  if (p.val !== q.val) return false;
  return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
}
