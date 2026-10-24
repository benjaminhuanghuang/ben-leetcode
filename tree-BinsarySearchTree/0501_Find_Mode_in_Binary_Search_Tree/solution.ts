/*
501. Find Mode in Binary Search Tree

https://leetcode.com/problems/find-mode-in-binary-search-tree/
*/

import { TreeNode } from "../Common/TreeNode";

/*
    Approach: Inorder Traversal 2 passes
    Count the number of nodes having the same value in the first pass.
*/

function findMode(root: TreeNode | null): number[] {
  // count of the duplicate values
  let count = 0;
  let currValue = 0;
  let max_count = 0;
  // count of the nodes having the same value, the value will be set after the first pass
  let mode_count = Number.MAX_SAFE_INTEGER;
  const ans: number[] = [];

  function inorderTraversal(root: TreeNode | null) {
    if (root === null) return;
    inorderTraversal(root.left);
    visit(root.val);
    inorderTraversal(root.right);
  }

  function visit(val: number) {
    if (count > 0 && val === currValue) {
      // the value of current node is the same as the previous node
      count++;
    } else {
      // encounter a new value
      currValue = val;
      count = 1;
    }
    if (count > max_count) {
      max_count = count;
    }
    // at pass2, if the count of the current value is equal to the mode_count, add it to the result
    if (count === mode_count) {
      ans.push(currValue);
    }
  }

  // pass 1: find the max count
  inorderTraversal(root);
  count = 0;
  mode_count = max_count;
  // pass 2: find the modes
  inorderTraversal(root);

  return ans;
}
