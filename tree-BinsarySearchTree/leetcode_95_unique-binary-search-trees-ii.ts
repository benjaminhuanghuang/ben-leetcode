/*
95. Unique Binary Search Trees II

https://leetcode.com/problems/unique-binary-search-trees-ii/

96. Unique Binary Search Trees (DP)
*/

import { TreeNode } from "../Common/TreeNode";

function generateTrees(n: number): Array<TreeNode | null> {
  if (n == 0) return [];
  return generateTreesHelper(1, n);
}

function generateTreesHelper(
  start: number,
  end: number
): Array<TreeNode | null> {
  const ans: Array<TreeNode | null> = [];

  if (start > end) {
    ans.push(null);
    return ans;
  }

  for (let i = start; i <= end; i++) {
    const leftTrees = generateTreesHelper(start, i - 1);
    const rightTrees = generateTreesHelper(i + 1, end);

    for (let left of leftTrees) {
      for (let right of rightTrees) {
        const root = new TreeNode(i);
        root.left = left;
        root.right = right;
        ans.push(root);
      }
    }
  }

  return ans;
}
