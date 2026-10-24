/*
449. Serialize and Deserialize BST

https://leetcode.com/problems/serialize-and-deserialize-bst/

- 297. Serialize and Deserialize Binary Tree
*/

import { TreeNode } from "../Common/TreeNode";

function serialize(root: TreeNode | null): string {
  if (!root) {
    return "";
  }
  let serialized = "";

  const preorderTraverse = (node: TreeNode | null): void => {
    if (node === null) {
      return;
    }
    serialized += `${node.val} `; // Adding a space after each value.
    preorderTraverse(node.left);
    preorderTraverse(node.right);
  };

  preorderTraverse(root);
  return serialized.trim(); // Removing the trailing space.
}

/*
 * Decodes your encoded data to tree.
 */
function deserialize(data: string): TreeNode | null {
  if (data.length === 0) {
    return null;
  }

  const values: number[] = split(data, " ");
  let index = 0;

  const constructTree = (
    minValue: number,
    maxValue: number
  ): TreeNode | null => {
    if (
      index === values.length ||
      values[index] < minValue ||
      values[index] > maxValue
    ) {
      return null;
    }

    const currentValue = values[index++];
    const node = new TreeNode(currentValue);

    node.left = constructTree(minValue, currentValue);
    node.right = constructTree(currentValue, maxValue);

    return node;
  };

  return constructTree(Number.MIN_SAFE_INTEGER, Number.MAX_SAFE_INTEGER);
}
// Utility function to split a string 's' by a delimiter 'delim' and returns an array of numbers.
const split = (s: string, delim: string): number[] => {
  return s.split(delim).map((str) => parseInt(str, 10));
};
