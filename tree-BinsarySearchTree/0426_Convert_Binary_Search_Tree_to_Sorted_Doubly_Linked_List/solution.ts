import { TreeNode } from "../../common/TreeNode";

/*
Approach: In-Order Traversal
To binary search tree, in-order traversal gives the nodes in ascending order.

https://algo.monster/liteproblems/426

Time complexity: O(N)
Space complexity: O(LogN) due to the recursion stack
*/

function treeToDoublyList(root: TreeNode | null): TreeNode | null {
  if (!root) return root;

  /*
        In the in-order traversal, we need to connect the result of the left subtree, 
        the current node, and the result of the right subtree together.
        The previous node is for the connection.
    */
  let previous: TreeNode | null = null;
  let head: TreeNode | null = null; // point to the leftmost node in the tree

  function inOrderTraversal(node: TreeNode | null): void {
    if (!node) return;

    // Traverse the left subtree
    inOrderTraversal(node!.left);

    // Link the current node with the previous node
    if (previous) {
      previous.right = node;
      node.left = previous;
    } else {
      // Set the head if this is the leftmost node
      head = node;
    }

    // Move the 'previous' pointer to the current node
    // Finally, the 'previous' pointer will be the rightmost node
    previous = node;

    // Traverse the right subtree
    inOrderTraversal(node.right);
  }
  // Start the in-order traversal
  inOrderTraversal(root);

  // Connect the head and tail to make the list circular
  if (head && previous) {
    (previous as TreeNode).right = head;
    (previous as TreeNode).left = previous;
  }

  return head;
}
