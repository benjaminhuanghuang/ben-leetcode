/*
872. Leaf-Similar Trees

https://leetcode.com/problems/leaf-similar-trees/
*/

import { TreeNode } from "../Common/TreeNode";

/*
https://zxi.mytechroad.com/blog/tree/leetcode-872-leaf-similar-trees/
Get the leaf sequence of each tree and compare them.
 */
function leafSimilar(root1: TreeNode | null, root2: TreeNode | null): boolean {
  const leaves1: number[] = [];
  const leaves2: number[] = [];

  function dfs(node: TreeNode | null, leaves: number[]) {
    if (node == null) return;

    if (node.left == null && node.right == null) {
      leaves.push(node.val);
      return;
    }

    dfs(node.left, leaves);
    dfs(node.right, leaves);
  }

  dfs(root1, leaves1);
  dfs(root2, leaves2);

  if (leaves1.length != leaves2.length) return false;

  for (let i = 0; i < leaves1.length; i++) {
    if (leaves1[i] != leaves2[i]) return false;
  }

  return true;
}
