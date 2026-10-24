/*
113. Path Sum II

https://leetcode.com/problems/path-sum-ii/
*/

import { TreeNode } from "../Common/TreeNode";

/*
    Find all the paths from root to leaf
*/
function pathSum(root: TreeNode | null, targetSum: number): number[][] {
  const ans: number[][] = [];
  const cur: number[] = [];

  pathSumHelper(root, targetSum, cur, ans);

  return ans;
}

function pathSumHelper(
  root: TreeNode | null,
  sum: number,
  curr: number[],
  ans: number[][]
): void {
  if (root === null) return;

  if (root.left === null && root.right === null) {
    if (root.val === sum) {
      curr.push(root.val);
      ans.push([...curr]);
      curr.pop(); // Remove the last element after pushing the path to ans
    }
    return;
  }

  curr.push(root.val);
  const newSum = sum - root.val;
  pathSumHelper(root.left, newSum, curr, ans);
  pathSumHelper(root.right, newSum, curr, ans);
  curr.pop();
}
