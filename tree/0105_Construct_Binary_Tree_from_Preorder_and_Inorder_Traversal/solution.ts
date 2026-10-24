/*
105. Construct Binary Tree from Preorder and Inorder Traversal
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/

import { TreeNode } from "../Common/TreeNode";

/*

Time complexity: O(n^2)
*/

function buildTree(preorder: number[], inorder: number[]): TreeNode | null {
  if (preorder.length === 0) {
    return null;
  }

  const root = new TreeNode(preorder[0]);
  const rootIndexInInOrder = inorder.indexOf(preorder[0]); // the right part of the rootIndexInInOrder is the right subtree

  root.left = buildTree(
    preorder.slice(1, rootIndexInInOrder + 1),
    inorder.slice(0, rootIndexInInOrder)
  );
  // to both of preoder and inorder, the right part of the rootIndexInInOrder is the right subtree
  root.right = buildTree(
    preorder.slice(rootIndexInInOrder + 1),
    inorder.slice(rootIndexInInOrder + 1)
  );

  return root;
}

function buildTree_2(preorder: number[], inorder: number[]): TreeNode | null {
  const inorderIndexMap: { [key: number]: number } = {};
  inorder.forEach((value, index) => {
    inorderIndexMap[value] = index;
  });

  let preorderIndex = 0;

  // Recursive function to build the tree using the preorder array
  function arrayToTree(left: number, right: number): TreeNode | null {
    if (left > right) return null;

    const rootValue = preorder[preorderIndex++];
    const root = new TreeNode(rootValue);

    root.left = arrayToTree(left, inorderIndexMap[rootValue] - 1);
    root.right = arrayToTree(inorderIndexMap[rootValue] + 1, right);

    return root;
  }

  return arrayToTree(0, preorder.length - 1);
}
