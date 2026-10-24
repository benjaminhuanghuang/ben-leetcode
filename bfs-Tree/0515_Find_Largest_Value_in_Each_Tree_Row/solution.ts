/*
515. Find Largest Value in Each Tree Row

https://leetcode.com/problems/find-largest-value-in-each-tree-row/

*/
import { TreeNode } from "../Common/TreeNode";

function largestValues(root: TreeNode | null): number[] {
  if (!root) return [];

  const res: number[] = [];
  const queue: TreeNode[] = [root];
  while (queue.length > 0) {
    let max = Number.MIN_SAFE_INTEGER;
    const size = queue.length;
    for (let i = 0; i < size; i++) {
      const node = queue.shift()!;
      max = Math.max(max, node.val);
      if (node.left) queue.push(node.left);
      if (node.right) queue.push(node.right);
    }
    res.push(max);
  }
  return res;
}
