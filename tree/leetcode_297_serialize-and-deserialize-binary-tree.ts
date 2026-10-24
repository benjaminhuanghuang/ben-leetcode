/*
297. Serialize and Deserialize Binary Tree
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
*/

import { TreeNode } from "../Common/TreeNode";
/*
 * Encodes a tree to a single string.
 * Pre-order traversal is used to serialize the tree
 */
function serialize(root: TreeNode | null): string {
  // Empty node is represented by a hash sign
  if (root === null) {
    return "#";
  }
  // Serialize the current node's value and recurse for the left and right subtrees
  return `${root.val},${serialize(root.left)},${serialize(root.right)}`;
}

/*
 * Decodes your encoded data to tree.
 */
function deserialize(data: string): TreeNode | null {
  // Split the data by commas and reverse it to prepare for the regeneration of the tree
  const values = data.split(",").reverse(); // right, left, root

  // A helper function to regenerate the tree from values
  const buildTree = (): TreeNode | null => {
    const current = values.pop(); // root
    // If the current part is a hash or undefined, it represents a null node
    if (current === undefined || current === "#") {
      return null;
    }
    // Otherwise, create a new TreeNode with the value and recursively build left and right subtrees
    return new TreeNode(Number(current), buildTree(), buildTree());
  };

  // Begin construction of the binary tree from the list of values
  return buildTree();
}
