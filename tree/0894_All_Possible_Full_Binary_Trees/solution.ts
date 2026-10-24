/*
894. All Possible Full Binary Trees

https://leetcode.com/problems/all-possible-full-binary-trees/
*/

import { TreeNode } from "../Common/TreeNode";
/*
https://www.youtube.com/watch?v=noVVstnQvyY (HuaHua)

trees():
    for i = 1 to n, step 2:
        root. left := trees(i)
        root.right := trees(n - i - 1)
*/

function allPossibleFBT(n: number): Array<TreeNode | null> {
  // Memoization to store already computed results
  const memo: Map<number, Array<TreeNode | null>> = new Map();

  function generateFBT(n: number): Array<TreeNode | null> {
    // Base case: if n is even, it's impossible to create a full binary tree
    if (n % 2 === 0) return [];

    // Base case: if n is 1, return a single node
    if (n === 1) return [new TreeNode(0)];

    // Check if we've already computed this result
    if (memo.has(n)) return memo.get(n)!;

    const result: Array<TreeNode | null> = [];

    // Generate all possible combinations of left and right subtrees
    for (let leftNodes = 1; leftNodes < n; leftNodes += 2) {
      const rightNodes = n - 1 - leftNodes;
      const leftSubtrees = generateFBT(leftNodes);
      const rightSubtrees = generateFBT(rightNodes);

      // Combine left and right subtrees
      for (const left of leftSubtrees) {
        for (const right of rightSubtrees) {
          const root = new TreeNode(0, left, right);
          result.push(root);
        }
      }
    }

    // Memoize the result before returning
    memo.set(n, result);
    return result;
  }

  return generateFBT(n);
}
