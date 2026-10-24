/*
979. Distribute Coins in Binary Tree

https://leetcode.com/problems/distribute-coins-in-binary-tree/
*/

import { TreeNode } from "../Common/TreeNode";
/*
https://zxi.mytechroad.com/blog/tree/leetcode-979-distribute-coins-in-binary-tree/ 

Compute the balance of left/right subtree, ans += abs(balance(left)) + abs(balance(right))

balance(root) = balance(left) + balance(right) + root.val – 1
balance is  node 和孩子一共多了多少金币, 或者欠了多少金币

Time complexity: O(n)
Space complexity: O(n)
*/

function distributeCoins(root: TreeNode | null): number {
  let ans = 0;

  function balance(root: TreeNode | null): number {
    if (!root) return 0;
    const l = balance(root.left);
    const r = balance(root.right);
    ans += Math.abs(l) + Math.abs(r);
    return l + r + root.val - 1;
  }

  balance(root);
  return ans;
}
