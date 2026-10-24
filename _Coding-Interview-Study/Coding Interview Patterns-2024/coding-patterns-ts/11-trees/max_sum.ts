import { TreeNode } from "./tree";

function maxPathSum(root: TreeNode | null): number {
  let maxSum = -Infinity;

  // 返回 以当前节点为终点的最大单边路径和
  function maxPathSumHelper(node: TreeNode | null): number {
    if (!node) return 0;

    // 最大贡献值（如果为负数就取 0）
    const leftSum = Math.max(maxPathSumHelper(node.left), 0);
    const rightSum = Math.max(maxPathSumHelper(node.right), 0);

    // 更新全局最大路径和
    maxSum = Math.max(maxSum, node.val + leftSum + rightSum);

    // 返回包含当前节点的单边最大路径和
    return node.val + Math.max(leftSum, rightSum);
  }

  maxPathSumHelper(root);
  return maxSum;
}

/*
Time complexity: The time complexity of max_path_sum is O(n). where n denotes the number of
nodes in the tree. This is because it traverses each node of the tree once.

Space complexity: The space complexity is O(n) due to the space taken up by the recursive call
stack, which can grow as large as the height of the binary tree. The largest possible height of a
binary tree is n.
*/
