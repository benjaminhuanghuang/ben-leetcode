/*
1008. Construct Binary Search Tree from Preorder Traversal

https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
*/

import { TreeNode } from "../Common/TreeNode";

/*
    in the preorder: 第一个元素表示树的根。根后面的元素随后被分成两个子数组：左子树元素和右子树。
    左子树包含所有小于root的元素，右子树包含所有大于root的元素。
*/
function bstFromPreorder(preorder: number[]): TreeNode | null {
  const length = preorder.length;
  // Initialize the next array to track the next greater element's index
  const nextGreaterIndex = new Array(length);
  // Stack to help find the next greater element
  const stack: number[] = [];

  // Iterate backwards through the preorder array to populate nextGreaterIndex
  for (let i = length - 1; i >= 0; i--) {
    // Pop elements from the stack until the current element is greater
    while (
      stack.length > 0 &&
      preorder[stack[stack.length - 1]] < preorder[i]
    ) {
      stack.pop();
    }
    // Assign the index of the next greater element or the length if not found
    nextGreaterIndex[i] = stack.length > 0 ? stack[stack.length - 1] : length;
    // Push the current index onto the stack
    stack.push(i);
  }

  // Recursive function to build the tree
  // 使用找到的边界之前的元素创建左子树，使用边界之后的元素创建右子树
  const dfs = (leftIndex: number, rightIndex: number): TreeNode | null => {
    // If the indices are the same, we've reached a leaf node, return null
    if (leftIndex >= rightIndex) {
      return null;
    }
    // Create the root TreeNode with the value from preorder traversal
    // The left child is built from the elements immediately after the root
    // The right child is built from elements after the left subtree
    return new TreeNode(
      preorder[leftIndex],
      dfs(leftIndex + 1, nextGreaterIndex[leftIndex]),
      dfs(nextGreaterIndex[leftIndex], rightIndex)
    );
  };

  return dfs(0, length);
}

function bstFromPreorder_2(preorder: number[]): TreeNode | null {
  const root = new TreeNode(preorder[0]);
  const stack: TreeNode[] = [root];

  for (let i = 1; i < preorder.length; ++i) {
    let parent = stack[stack.length - 1]; // Parent is the last element in the stack.
    const child = new TreeNode(preorder[i]);

    // Adjust the parent.
    while (stack.length > 0 && stack[stack.length - 1].val < child.val) {
      parent = stack.pop()!;
    }

    // Create parent-child link according to BST property.
    if (parent.val > child.val) {
      parent.left = child;
    } else {
      parent.right = child;
    }

    stack.push(child);
  }

  return root;
}
