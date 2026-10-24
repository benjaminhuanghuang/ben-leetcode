/*
106. Construct Binary Tree from Inorder and Postorder Traversal
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
*/
import { TreeNode } from "../Common/TreeNode";

/*
 inorder:   [-left-][root][--right--]
 postorder: [-left-][--right--][root]
*/
function buildTree(inorder: number[], postorder: number[]): TreeNode | null {
  if (inorder.length === 0) {
    return null;
  }

  const root = new TreeNode(postorder[postorder.length - 1]);
  const rootIndexInInOrder = inorder.indexOf(postorder[postorder.length - 1]); // the right part of the rootIndexInInOrder is the right subtree

  // to both of inorder and postorder, the left part of the rootIndexInInOrder is the left subtree
  root.left = buildTree(
    inorder.slice(0, rootIndexInInOrder),
    postorder.slice(0, rootIndexInInOrder)
  );
  // In postorder, the right part of the rootIndexInInOrder is the right subtree
  root.right = buildTree(
    inorder.slice(rootIndexInInOrder + 1),
    postorder.slice(rootIndexInInOrder, postorder.length - 1)
  );

  return root;
}
