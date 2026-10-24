import { TreeNode } from "./tree";

function lowestCommonAncestor(
  root: TreeNode | null,
  p: TreeNode,
  q: TreeNode
): TreeNode | null {
  let lca: TreeNode | null = null;

  // returns true if the subtree rooted at 'node' contains either p or q
  function dfs(node: TreeNode | null): boolean {
    if (!node) return false;

    const nodeIsPOrQ = node === p || node === q;

    const leftContains = dfs(node.left);
    const rightContains = dfs(node.right);

    // If any two of nodeIsPOrQ, leftContains, rightContains are true, current node is LCA
    // 如果一个节点在左子树，另一个在右子树，或者当前节点就是 p/q，另一个在某个子树中，那么当前节点就是两者最近的共同祖先。
    if (
      (nodeIsPOrQ ? 1 : 0) + (leftContains ? 1 : 0) + (rightContains ? 1 : 0) >=
      2
    ) {
      lca = node;
    }

    // Return true if this subtree contains p or q
    return nodeIsPOrQ || leftContains || rightContains;
  }

  dfs(root);
  return lca;
}

/*
Time complexity: The time complexity of lowest_common_ancestor is O(n), where n denotes the
number of nodes in the tree. This is because the algorithm traverses each node of the tree once.

Space complexity: The space complexity is O(n) due to the space taken up by the recursive call
stack, which can grow as large as the height of the binary tree. The largest possible height of a
binary tree is n.
*/
