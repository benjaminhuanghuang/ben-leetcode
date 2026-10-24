import { TreeNode } from "./tree";

function rightmostNodesOfABinaryTree(root: TreeNode | null): number[] {
  if (root === null) return [];

  const res: number[] = [];
  const queue: (TreeNode | null)[] = [root];

  while (queue.length > 0) {
    const levelSize = queue.length;

    for (let i = 0; i < levelSize; i++) {
      const node = queue.shift()!; // Non-null assertion since queue isn’t empty

      // Enqueue children for the next level
      if (node.left) queue.push(node.left);
      if (node.right) queue.push(node.right);

      // Record the last node's value at this level
      if (i === levelSize - 1) {
        res.push(node.val);
      }
    }
  }

  return res;
}

/*
Time complexity: The time complexity of rightmost_nodes_of _a_binary_tree is O(n), where n
denotes the number of nodes in the tree. This is because we process each node of the tree once
during the level-order traversal.

Space complexity: The space complexity is O(n) due to the space taken up by the queue. The
queue's size will grow as large as the level with the most nodes. In the worst case, this occurs at
the final level when all the last-level nodes are non-null, totaling approximately n/2 nodes. Note
that the res array does not contribute to the space complexity.
*/
