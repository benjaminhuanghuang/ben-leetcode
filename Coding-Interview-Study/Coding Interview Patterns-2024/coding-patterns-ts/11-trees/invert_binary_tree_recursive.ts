import { TreeNode } from "./tree";

function invert_binary_tree_recursive(root: TreeNode | null): TreeNode | null {
  // Base case: If the node is null, there's nothing to invert.
  if (!root) {
    return null;
  }

  // Swap the left and right subtrees of the current node.
  [root.left, root.right] = [root.right, root.left];

  // Recursively invert the left and right subtrees.
  invert_binary_tree_recursive(root.left);
  invert_binary_tree_recursive(root.right);

  return root;
}

/*
Time complexity: The time complexity of invert_binary_tree_recursive is O(n), where n denotes
the number of nodes in the tree. This is because the algorithm traverses each node of the
binary tree exactly once.

Space complexity: The space complexity is O(n) due to the space taken up by the recursive call
stack, which can grow as large as the height of the binary tree. The largest possible height of a
binary tree is n.
*/
