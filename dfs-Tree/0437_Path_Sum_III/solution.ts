/*
437. Path Sum III

https://leetcode.com/problems/path-sum-iii/
*/

import { TreeNode } from "../Common/TreeNode";

/*
https://zxi.mytechroad.com/blog/tree/leetcode-437-path-sum-iii/
 
Recursion
Time complexity: O(n^2)

Space complexity: O(n)
 */
function pathSum(root: TreeNode | null, targetSum: number): number {
  if (!root) {
    return 0;
  }
  return (
    numberOfPaths(root, targetSum) +
    pathSum(root.left, targetSum) +
    pathSum(root.right, targetSum)
  );
}

function numberOfPaths(root: TreeNode | null, sum: number): number {
  if (!root) {
    return 0;
  }
  sum -= root.val;
  return (
    (sum === 0 ? 1 : 0) +
    numberOfPaths(root.left, sum) +
    numberOfPaths(root.right, sum)
  );
}
