import { TreeNode } from "./tree";

function invert_binary_tree_iterative(root: TreeNode | null): TreeNode | null {
  if (!root) {
    return null;
  }

  const stack: TreeNode[] = [root];

  while (stack.length > 0) {
    const node = stack.pop()!;

    // Swap the left and right subtrees of the current node.
    [node.left, node.right] = [node.right, node.left];

    // Push the left and right subtrees onto the stack.
    if (node.left) {
      stack.push(node.left);
    }

    if (node.right) {
      stack.push(node.right);
    }
  }

  return root;
}
/*
Time complexity: The time complexity of invert_binary_tree_iterative is O(n) because it
processes each node in the binary tree exactly once.

Space complexity: The space complexity is O(n) due to the space taken up by the stack, which can
grow as large as the height of the binary tree. The largest possible height of a binary tree is n.
*/
