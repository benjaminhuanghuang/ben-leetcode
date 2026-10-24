import { TreeNode } from "../../common/TreeNode";

/*
Post-order DFS. For each node, track the longest zigzag path that starts at
that node going left first, and the longest going right first. A left-first
path at a node is 1 + (right-first path of its left child); same symmetrically
for right-first. Track the max seen across all nodes.

Time complexity: O(n)
Space complexity: O(h), h is the height of the tree (recursion stack)
*/
function longestZigZag(root: TreeNode | null): number {
  let maxLen = 0;

  function dfs(node: TreeNode | null): [number, number] {
    if (node === null) return [-1, -1];

    const [, leftRight] = dfs(node.left);
    const [rightLeft] = dfs(node.right);

    const left = leftRight + 1;
    const right = rightLeft + 1;

    maxLen = Math.max(maxLen, left, right);

    return [left, right];
  }

  dfs(root);

  return maxLen;
}

export {};
