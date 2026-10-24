/*
124. Binary Tree Maximum Path Sum

https://leetcode.com/problems/binary-tree-maximum-path-sum/

[Google]
*/

import { TreeNode } from "../Common/TreeNode";

/*
LaiOffer
https://www.youtube.com/watch?v=WicS0ANkAdY&list=PLTNkreZiUTIL-S_VJBLRxlmGktAQtla-m&index=1
*/

// 1 左子树的路径加上当前节点，
// 2 右子树的路径加上当前节点，
// 3 左右子树的路径加上当前节点（相当于一条横跨当前节点的路径），
// 4 只有自己的路径。
function maxPathSum(root: TreeNode | null): number {
  let maxPath = Number.MIN_SAFE_INTEGER;

  // 以root 为顶点的所有直上直下的path中 sum 最大的一路径的值
  function maxPathSumFromRootToLeaf(root: TreeNode | null): number {
    if (root == null) return 0;

    const left = maxPathSumFromRootToLeaf(root.left);
    const right = maxPathSumFromRootToLeaf(root.right);
    // Calculate return value, cover case: 1,2,4, result = max path sum from root to leaf
    const result = Math.max(Math.max(left, right) + root.val, root.val);
    // case: 1,2,3,4
    maxPath = Math.max(maxPath, Math.max(result, left + right + root.val));
    return result;
  }

  maxPathSumFromRootToLeaf(root); // update maxPath during the recursion
  return maxPath;
}

function maxPathSum2(root: TreeNode | null): number {
  let maxSum = -Infinity;

  // 以当前节点为起点，向下延伸的最大路径和
  function dfs(node: TreeNode | null): number {
    if (!node) return 0;

    // 计算左右子树最大贡献值
    const left = Math.max(0, dfs(node.left));
    const right = Math.max(0, dfs(node.right));

    // 更新全局最大值（路径可以左右都选）
    maxSum = Math.max(maxSum, left + right + node.val);

    // 返回给父节点的值（只能选一边）
    return node.val + Math.max(left, right);
  }

  dfs(root);
  return maxSum;
}
