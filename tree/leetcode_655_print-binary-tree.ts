/*
655. Print Binary Tree

https://leetcode.com/problems/print-binary-tree/
*/
import { TreeNode } from "../Common/TreeNode";

/*
https://zxi.mytechroad.com/blog/tree/leetcode-655-print-binary-tree/

 */

function printTree(root: TreeNode | null): string[][] {
  const h = getHeight(root);
  const w = (1 << h) - 1; // 2 ^ h - 1
  const ans: string[][] = Array.from({ length: h }, () => Array(w).fill(""));
  fill(root, ans, 0, 0, w - 1);
  return ans;
}

function getHeight(root: TreeNode | null): number {
  if (root === null) return 0;
  return Math.max(getHeight(root.left), getHeight(root.right)) + 1;
}

function fill(
  root: TreeNode | null,
  ans: string[][],
  h: number,
  l: number,
  r: number
): void {
  if (root === null) return;
  const mid = Math.floor((l + r) / 2);
  ans[h][mid] = root.val.toString();
  fill(root.left, ans, h + 1, l, mid - 1);
  fill(root.right, ans, h + 1, mid + 1, r);
}
