/*
1038. Binary Search Tree to Greater Sum Tree

https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
*/
import { TreeNode } from "../Common/TreeNode";

/*
BST: 左子树 < 当前节点 < 右子树
Greater Sum Tree 的定义： 每个节点的新值 = 原值 + 所有 大于它的节点值之和

Morris Traversal：不用递归，也不用栈，利用树结构本身建立临时“线程”来回溯

BST 的中序遍历是: 左 → 根 → 右   （从小到大）

先处理右子树是为了保证每个节点能加上所有比它大的节点值。
*/

function bstToGst(root: TreeNode | null): TreeNode | null {
  let current = root;
  let totalSum = 0; // 累积节点值之和 It accumulates all the values of nodes that are greater than or equal to the current node

  while (current != null) {
    // 先处理右子树（逆中序顺序）
    let rightNode = current.right;
    //获得大于当前节点的节点总和，按照中序遍历的逆序来处理节点
    if (rightNode == null) {
      totalSum += current.val; // Update the total sum with current value
      current.val = totalSum; // Modify the current node's value to total sum
      current = current.left; // Move to the left“先处理右子树”是为了保证每个节点能加上所有比它大的节点值。 subtree
    } else {
      // Find the leftmost node in the current's right subtree
      let leftMost = rightNode;
      while (leftMost.left != null && leftMost.left != current) {
        // leftMost.left != current 用于判断是否已经建立过 thread
        leftMost = leftMost.left;
      }

      // First time visiting this right subtree, make a thread back to current
      if (leftMost.left == null) {
        leftMost.left = current; // Create a thread back to current
        current = rightNode;
      } else {
        // Second time visiting - the thread is already there
        leftMost.left = null; // Remove the thread
        totalSum += current.val; // Update the total sum with current value
        current.val = totalSum; // Modify the current node's value to the total sum
        current = current.left; // Move to the left subtree
      }
    }
  }

  return root;
}
/*
Use reverse in-order traversal: Right → Node → Left

Time: O(n) → each node visited once
Space: O(h) → recursion stack, h = tree height
*/
function bstToGst2(root: TreeNode | null): TreeNode | null {
  let totalSum = 0;

  function reverseInorder(node: TreeNode | null) {
    if (!node) return;

    // 1. Traverse right subtree first (larger nodes)
    reverseInorder(node.right);

    // 2. Update current node
    totalSum += node.val;
    node.val = totalSum;

    // 3. Traverse left subtree
    reverseInorder(node.left);
  }

  reverseInorder(root);
  return root;
}
