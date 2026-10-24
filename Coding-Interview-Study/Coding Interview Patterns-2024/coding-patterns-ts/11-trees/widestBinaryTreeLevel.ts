import { TreeNode } from "./tree";

/*
Return the width of the widest level in a binary tree, where the width of a level is defined
as the distance between its leftmost and rightmost non-null nodes.

核心思路

  使用 层序遍历（BFS） 来遍历二叉树。
  给每个节点标记 索引，就像完全二叉树那样：
    根节点索引 = 0
    左子节点索引 = 2 * parentIndex + 1
    右子节点索引 = 2 * parentIndex + 2
  每一层的宽度 = 该层最右节点索引 - 最左节点索引 + 1
  更新最大宽度。
*/

function widestBinaryTreeLevel(root: TreeNode | null): number {
  if (root === null) return 0;

  let maxWidth = 0;
  // Queue holds [node, index] pairs (like in a complete binary tree)
  const queue: [TreeNode, number][] = [[root, 0]];

  while (queue.length > 0) {
    const levelSize = queue.length;

    // The index of the first node in this level
    const leftmostIndex = queue[0][1];
    let rightmostIndex = leftmostIndex;

    for (let i = 0; i < levelSize; i++) {
      const [node, index] = queue.shift()!;

      // Normalize the index to prevent overflow
      // 用每层最左节点的索引作为基准
      const normalizedIndex = index - leftmostIndex;

      // Push children with new calculated positions
      if (node.left) queue.push([node.left, 2 * normalizedIndex + 1]);
      if (node.right) queue.push([node.right, 2 * normalizedIndex + 2]);

      rightmostIndex = index;
    }

    // Calculate width for this level
    const width = rightmostIndex - leftmostIndex + 1;
    maxWidth = Math.max(maxWidth, width);
  }

  return maxWidth;
}
/*
Time complexity: The time complexity of widestBinaryTreeLevel is O(n), where n
denotes the number of nodes in the tree. This is because we process each node of the tree once
during the level-order traversal.

Space complexity: The space complexity is O(n) due to the space taken up by the queue. The
queue's size will grow as large as the level with the most nodes. In the worst case, this occurs at
the final level when all the last-level nodes are non-null, totaling approximately n/2 nodes. Note
that the res array does not contribute to the space complexity.
*/
